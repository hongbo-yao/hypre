/*BHEADER**********************************************************************
 * Copyright (c) 2006   The Regents of the University of California.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by the HYPRE team <hypre-users@llnl.gov>, UCRL-CODE-222953.
 * All rights reserved.
 *
 * This file is part of HYPRE (see http://www.llnl.gov/CASC/hypre/).
 * Please see the COPYRIGHT_and_LICENSE file for the copyright notice, 
 * disclaimer and the GNU Lesser General Public License.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License (as published by the Free
 * Software Foundation) version 2.1 dated February 1999.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the IMPLIED WARRANTY OF MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the terms and conditions of the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * $Revision$
 ***********************************************************************EHEADER*/



/*
 * -- SuperLU routine (version 2.0) --
 * Univ. of California Berkeley, Xerox Palo Alto Research Center,
 * and Lawrence Berkeley National Lab.
 * November 15, 1997
 *
 */
/*
  Copyright (c) 1994 by Xerox Corporation.  All rights reserved.
 
  THIS MATERIAL IS PROVIDED AS IS, WITH ABSOLUTELY NO WARRANTY
  EXPRESSED OR IMPLIED.  ANY USE IS AT YOUR OWN RISK.
 
  Permission is hereby granted to use or copy this program for any
  purpose, provided the above notices are retained on all copies.
  Permission to modify the code and to distribute modified code is
  granted, provided the above notices are retained, and a notice that
  the code was modified is included with the above copyright notice.

  Changes made to this file corresponding to calls to blas/lapack functions
  in Nov 2003 at LLNL
*/

#include "dsp_defs.h"
#include "superlu_util.h"

#ifndef HYPRE_USING_HYPRE_BLAS
#define USE_VENDOR_BLAS
#endif

/* 
 * Function prototypes 
 */
void sludusolve(int, int, double*, double*);
void sludlsolve(int, int, double*, double*);
void sludmatvec(int, int, int, double*, double*, double*);


void
dgstrs (char *trans, SuperMatrix *L, SuperMatrix *U,
	int *perm_r, int *perm_c, SuperMatrix *B, int *info)
{
/*
 * Purpose
 * =======
 *
 * DGSTRS solves a system of linear equations A*X=B or A'*X=B
 * with A sparse and B dense, using the LU factorization computed by
 * DGSTRF.
 *
 * See supermatrix.h for the definition of 'SuperMatrix' structure.
 *
 * Arguments
 * =========
 *
 * trans   (input) char*
 *          Specifies the form of the system of equations:
 *          = 'N':  A * X = B  (No transpose)
 *          = 'T':  A'* X = B  (Transpose)
 *          = 'C':  A**H * X = B  (Conjugate transpose)
 *
 * L       (input) SuperMatrix*
 *         The factor L from the factorization Pr*A*Pc=L*U as computed by
 *         dgstrf(). Use compressed row subscripts storage for supernodes,
 *         i.e., L has types: Stype = SC, Dtype = D_D, Mtype = TRLU.
 *
 * U       (input) SuperMatrix*
 *         The factor U from the factorization Pr*A*Pc=L*U as computed by
 *         dgstrf(). Use column-wise storage scheme, i.e., U has types:
 *         Stype = NC, Dtype = D_D, Mtype = TRU.
 *
 * perm_r  (input) int*, dimension (L->nrow)
 *         Row permutation vector, which defines the permutation matrix Pr; 
 *         perm_r[i] = j means row i of A is in position j in Pr*A.
 *
 * perm_c  (input) int*, dimension (L->ncol)
 *	   Column permutation vector, which defines the 
 *         permutation matrix Pc; perm_c[i] = j means column i of A is 
 *         in position j in A*Pc.
 *
 * B       (input/output) SuperMatrix*
 *         B has types: Stype = DN, Dtype = D_D, Mtype = GE.
 *         On entry, the right hand side matrix.
 *         On exit, the solution matrix if info = 0;
 *
 * info    (output) int*
 * 	   = 0: successful exit
 *	   < 0: if info = -i, the i-th argument had an illegal value
 *
 */
#ifdef _CRAY
    _fcd ftcs1, ftcs2, ftcs3, ftcs4;
#endif
#ifdef USE_VENDOR_BLAS
    double   alpha = 1.0, beta = 1.0;
#endif
    DNformat *Bstore;
    double   *Bmat;
    SCformat *Lstore;
    NCformat *Ustore;
    double   *Lval, *Uval;
    int      nrow, notran;
    int      fsupc, nsupr, nsupc, luptr, istart, irow;
    int      i, j, k, iptr, jcol, n, ldb, nrhs;
    double   *work, *rhs_work, *soln;
#ifdef USE_VENDOR_BLAS
    double   *work_col;
#endif
    flops_t  solve_ops;
    extern SuperLUStat_t SuperLUStat;
#ifdef DEBUG
    void dprint_soln();
#endif

    /* Test input parameters ... */
    *info = 0;
    Bstore = B->Store;
    ldb = Bstore->lda;
    nrhs = B->ncol;
    notran = superlu_lsame(trans, "N");
    if ( !notran && !superlu_lsame(trans, "T") && !superlu_lsame(trans, "C") ) 
        *info = -1;
    else if ( L->nrow != L->ncol || L->nrow < 0 ||
	      L->Stype != SC || L->Dtype != D_D || L->Mtype != TRLU )
	*info = -2;
    else if ( U->nrow != U->ncol || U->nrow < 0 ||
	      U->Stype != NC || U->Dtype != D_D || U->Mtype != TRU )
	*info = -3;
    else if ( ldb < MAX(0, L->nrow) ||
	      B->Stype != DN || B->Dtype != D_D || B->Mtype != GE )
	*info = -6;
    if ( *info ) {
	i = -(*info);
	superlu_xerbla("dgstrs", &i);
	return;
    }

    n = L->nrow;
    work = doubleCalloc(n * nrhs);
    if ( !work ) ABORT("Malloc fails for local work[].");
    soln = doubleMalloc(n);
    if ( !soln ) ABORT("Malloc fails for local soln[].");

    Bmat = Bstore->nzval;
    Lstore = L->Store;
    Lval = Lstore->nzval;
    Ustore = U->Store;
    Uval = Ustore->nzval;
    solve_ops = 0;
    
    if ( notran ) {
	/* Permute right hand sides to form Pr*B */
	for (i = 0; i < nrhs; i++) {
	    rhs_work = &Bmat[i*ldb];
	    for (k = 0; k < n; k++) soln[perm_r[k]] = rhs_work[k];
	    for (k = 0; k < n; k++) rhs_work[k] = soln[k];
	}
	
	/* Forward solve PLy=Pb. */
	for (k = 0; k <= Lstore->nsuper; k++) {
	    fsupc = L_FST_SUPC(k);
	    istart = L_SUB_START(fsupc);
	    nsupr = L_SUB_START(fsupc+1) - istart;
	    nsupc = L_FST_SUPC(k+1) - fsupc;
	    nrow = nsupr - nsupc;

	    solve_ops += nsupc * (nsupc - 1) * nrhs;
	    solve_ops += 2 * nrow * nsupc * nrhs;
	    
	    if ( nsupc == 1 ) {
		for (j = 0; j < nrhs; j++) {
		    rhs_work = &Bmat[j*ldb];
	    	    luptr = L_NZ_START(fsupc);
		    for (iptr=istart+1; iptr < L_SUB_START(fsupc+1); iptr++){
			irow = L_SUB(iptr);
			++luptr;
			rhs_work[irow] -= rhs_work[fsupc] * Lval[luptr];
		    }
		}
	    } else {
	    	luptr = L_NZ_START(fsupc);
#ifdef USE_VENDOR_BLAS
#ifdef _CRAY
		ftcs1 = _cptofcd("L", strlen("L"));
		ftcs2 = _cptofcd("N", strlen("N"));
		ftcs3 = _cptofcd("U", strlen("U"));
		STRSM( ftcs1, ftcs1, ftcs2, ftcs3, &nsupc, &nrhs, &alpha,
		       &Lval[luptr], &nsupr, &Bmat[fsupc], &ldb);
		
		SGEMM( ftcs2, ftcs2, &nrow, &nrhs, &nsupc, &alpha, 
			&Lval[luptr+nsupc], &nsupr, &Bmat[fsupc], &ldb, 
			&beta, &work[0], &n );
#else
		hypre_F90_NAME_BLAS(dtrsm,DTRSM)("L", "L", "N", "U", &nsupc, &nrhs, &alpha,
		       &Lval[luptr], &nsupr, &Bmat[fsupc], &ldb);
		
		hypre_F90_NAME_BLAS(dgemm,DGEMM)( "N", "N", &nrow, &nrhs, &nsupc, &alpha, 
			&Lval[luptr+nsupc], &nsupr, &Bmat[fsupc], &ldb, 
			&beta, &work[0], &n );
#endif
		for (j = 0; j < nrhs; j++) {
		    rhs_work = &Bmat[j*ldb];
		    work_col = &work[j*n];
		    iptr = istart + nsupc;
		    for (i = 0; i < nrow; i++) {
			irow = L_SUB(iptr);
			rhs_work[irow] -= work_col[i]; /* Scatter */
			work_col[i] = 0.0;
			iptr++;
		    }
		}
#else		
		for (j = 0; j < nrhs; j++) {
		    rhs_work = &Bmat[j*ldb];
		    sludlsolve (nsupr, nsupc, &Lval[luptr], &rhs_work[fsupc]);
		    sludmatvec (nsupr, nrow, nsupc, &Lval[luptr+nsupc],
			    &rhs_work[fsupc], &work[0] );

		    iptr = istart + nsupc;
		    for (i = 0; i < nrow; i++) {
			irow = L_SUB(iptr);
			rhs_work[irow] -= work[i];
			work[i] = 0.0;
			iptr++;
		    }
		}
#endif		    
	    } /* else ... */
	} /* for L-solve */

#ifdef DEBUG
  	printf("After L-solve: y=\n");
	dprint_soln(n, nrhs, Bmat);
#endif

	/*
	 * Back solve Ux=y.
	 */
	for (k = Lstore->nsuper; k >= 0; k--) {
	    fsupc = L_FST_SUPC(k);
	    istart = L_SUB_START(fsupc);
	    nsupr = L_SUB_START(fsupc+1) - istart;
	    nsupc = L_FST_SUPC(k+1) - fsupc;
	    luptr = L_NZ_START(fsupc);

	    solve_ops += nsupc * (nsupc + 1) * nrhs;

	    if ( nsupc == 1 ) {
		rhs_work = &Bmat[0];
		for (j = 0; j < nrhs; j++) {
		    rhs_work[fsupc] /= Lval[luptr];
		    rhs_work += ldb;
		}
	    } else {
#ifdef USE_VENDOR_BLAS
#ifdef _CRAY
		ftcs1 = _cptofcd("L", strlen("L"));
		ftcs2 = _cptofcd("U", strlen("U"));
		ftcs3 = _cptofcd("N", strlen("N"));
		STRSM( ftcs1, ftcs2, ftcs3, ftcs3, &nsupc, &nrhs, &alpha,
		       &Lval[luptr], &nsupr, &Bmat[fsupc], &ldb);
#else
		hypre_F90_NAME_BLAS(dtrsm,DTRSM)("L", "U", "N", "N", &nsupc, &nrhs, &alpha,
		       &Lval[luptr], &nsupr, &Bmat[fsupc], &ldb);
#endif
#else		
		for (j = 0; j < nrhs; j++)
		    sludusolve (nsupr, nsupc, &Lval[luptr], &Bmat[fsupc+j*ldb]);
#endif		
	    }

	    for (j = 0; j < nrhs; ++j) {
		rhs_work = &Bmat[j*ldb];
		for (jcol = fsupc; jcol < fsupc + nsupc; jcol++) {
		    solve_ops += 2*(U_NZ_START(jcol+1) - U_NZ_START(jcol));
		    for (i = U_NZ_START(jcol); i < U_NZ_START(jcol+1); i++ ){
			irow = U_SUB(i);
			rhs_work[irow] -= rhs_work[jcol] * Uval[i];
		    }
		}
	    }
	    
	} /* for U-solve */

#ifdef DEBUG
  	printf("After U-solve: x=\n");
	dprint_soln(n, nrhs, Bmat);
#endif

	/* Compute the final solution X := Pc*X. */
	for (i = 0; i < nrhs; i++) {
	    rhs_work = &Bmat[i*ldb];
	    for (k = 0; k < n; k++) soln[k] = rhs_work[perm_c[k]];
	    for (k = 0; k < n; k++) rhs_work[k] = soln[k];
	}
	
        SuperLUStat.ops[SOLVE] = solve_ops;

    } else { /* Solve A'*X=B */
	/* Permute right hand sides to form Pc'*B. */
	for (i = 0; i < nrhs; i++) {
	    rhs_work = &Bmat[i*ldb];
	    for (k = 0; k < n; k++) soln[perm_c[k]] = rhs_work[k];
	    for (k = 0; k < n; k++) rhs_work[k] = soln[k];
	}

	SuperLUStat.ops[SOLVE] = 0;
	
	for (k = 0; k < nrhs; ++k) {
	    
	    /* Multiply by inv(U'). */
	    sp_dtrsv("U", "T", "N", L, U, &Bmat[k*ldb], info);
	    
	    /* Multiply by inv(L'). */
	    sp_dtrsv("L", "T", "U", L, U, &Bmat[k*ldb], info);
	    
	}
	
	/* Compute the final solution X := Pr'*X (=inv(Pr)*X) */
	for (i = 0; i < nrhs; i++) {
	    rhs_work = &Bmat[i*ldb];
	    for (k = 0; k < n; k++) soln[k] = rhs_work[perm_r[k]];
	    for (k = 0; k < n; k++) rhs_work[k] = soln[k];
	}

    }

    SUPERLU_FREE(work);
    SUPERLU_FREE(soln);
}

/*
 * Diagnostic print of the solution vector 
 */
void
dprint_soln(int n, int nrhs, double *soln)
{
    int i;

    for (i = 0; i < n; i++) 
  	printf("\t%d: %.4f\n", i, soln[i]);
}
