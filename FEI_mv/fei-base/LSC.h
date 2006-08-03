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

#ifndef _LSC_h_
#define _LSC_h_

//
//Files that need to be included before the compiler
//reaches this header:
//
//#include "src/Data.h"
//#include <mpi.h>

class LSC : public LinearSystemCore {
 public:
   LSC(){};
   virtual ~LSC() {};

   //for cloning a LSC instance.
   virtual LinearSystemCore* clone() = 0;

   //int parameters:
   //for setting generic argc/argv style parameters.

   virtual int parameters(int numParams, char** params) = 0;

   virtual int setLookup(Lookup& lookup);

   virtual int setConnectivities(GlobalID elemBlock,
                                  int numElements,
                                  int numNodesPerElem,
                                  const GlobalID* elemIDs,
                                  const int* const* connNodes) ;

   virtual int setStiffnessMatrices(GlobalID elemBlock,
                                     int numElems,
                                     const GlobalID* elemIDs,
                                     const double *const *const *stiff,
                                     int numEqnsPerElem,
                                     const int *const * eqnIndices);

   virtual int setLoadVectors(GlobalID elemBlock,
                               int numElems,
                               const GlobalID* elemIDs,
                               const double *const * load,
                               int numEqnsPerElem,
                               const int *const * eqnIndices);

   virtual int setMultCREqns(int multCRSetID,
                              int numCRs, int numNodesPerCR,
                              int** nodeNumbers, int** eqnNumbers,
                              int* fieldIDs,
                              int* multiplierEqnNumbers);

   virtual int setPenCREqns(int penCRSetID,
                              int numCRs, int numNodesPerCR,
                              int** nodeNumbers, int** eqnNumbers,
                              int* fieldIDs);

   //for providing nodal data associated with a particular fieldID.
   //nodeNumbers is a list of length numNodes.
   //offsets is a list of length numNodes+1.
   //data contains the incoming data. data for the ith node lies in the
   //locations data[offsets[i]] ... data[offsets[i+1] -1 ]

   virtual int putNodalFieldData(int fieldID, int fieldSize,
                                  int* nodeNumbers, int numNodes,
                                  const double* data);

 private:
   int LSCmessageAbort(const char* name);
};

#endif

