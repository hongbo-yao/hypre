#ifndef _LinearSystemCore_h_
#define _LinearSystemCore_h_

//
//When creating a specific FEI implementation, i.e., a version that
//supports a specific underlying linear solver library, the main
//task that must be performed is the implementation of a class that
//derives from this class, LinearSystemCore.
//
//This is the class that holds and manipulates all solver-library-specific
//stuff, such as matrices/vectors, solvers/preconditioners, etc. An
//instance of this class is owned and used by the class that implements
//the FEI spec. i.e., when element contributions, etc., are received from
//the application, the data is ultimately passed to this class for 
//assembly into the sparse matrix and associated vectors. This class
//will also be asked to launch any underlying solver, and finally to
//return the solution.
//
//See the file LinearSystemCore.README for descriptions of required
//behavior and semantics for each of the member functions.
//
//

//Files that need to be included before the compiler
//reaches this header:
//
//#include "src/Data.h"
//#include <mpi.h>

class LinearSystemCore {
 public:
   LinearSystemCore(MPI_Comm comm){(void)comm;};
                                 //void cast prevents "un-used variable" warn.
   virtual ~LinearSystemCore(){};

   //for cloning a LinearSystemCore instance.
   virtual LinearSystemCore* clone() = 0;

   //void parameters:
   //for setting generic argc/argv style parameters.

   virtual void parameters(int numParams, char** params) = 0;

   //
   //Functions for creating, allocating, filling matrix/vector
   //structures.
   //

   virtual void createMatricesAndVectors(int numGlobalEqns, 
                                      int firstLocalEqn,
                                      int numLocalEqns) = 0;

   virtual void allocateMatrix(int** colIndices, int* rowLengths) = 0;

   virtual void sumIntoSystemMatrix(int row, int numValues,
                                    const double* values,
                                    const int* scatterIndices) = 0;

   virtual void sumIntoRHSVector(int num, const double* values,
                                 const int* indices) = 0;

   virtual void matrixLoadComplete() = 0;
   
   virtual void resetMatrixAndVector(double s) = 0;

   //functions for enforcing boundary conditions.
   virtual void enforceEssentialBC(int* globalEqn, double* alpha,
                                   double* gamma, int len) = 0;
   virtual void enforceRemoteEssBCs(int numEqns, int* globalEqns,
                                          int** colIndices, int* colIndLen,
                                          double** coefs) = 0;
   virtual void enforceOtherBC(int* globalEqn, double* alpha,
                               double* beta, double* gamma, int len) = 0;

   //functions for getting/setting matrix or rhs vector(s), or pointers to them.

   virtual void getMatrixPtr(Data& data) = 0;

   virtual void copyInMatrix(double scalar, const Data& data) = 0;
   virtual void copyOutMatrix(double scalar, Data& data) = 0;
   virtual void sumInMatrix(double scalar, const Data& data) = 0;

   virtual void getRHSVectorPtr(Data& data) = 0;

   virtual void copyInRHSVector(double scalar, const Data& data) = 0;
   virtual void copyOutRHSVector(double scalar, Data& data) = 0;
   virtual void sumInRHSVector(double scalar, const Data& data) = 0;

   //Utility functions for destroying matrix or vector in a Data container.
   //The caller (owner of 'data') can't destroy the matrix because they don't
   //know what type it is and can't get to its destructor.

   virtual void destroyMatrixData(Data& data) = 0;
   virtual void destroyVectorData(Data& data) = 0;

   //functions for managing multiple rhs vectors
   virtual void setNumRHSVectors(int numRHSs, const int* rhsIDs) = 0;
   virtual void setRHSID(int rhsID) = 0;

   //functions for getting/setting the contents of the solution vector.

   virtual void putInitialGuess(const int* eqnNumbers, const double* values,
                                int len) = 0;

   virtual void getSolution(int* eqnNumbers, double* answers, int len) = 0;

   virtual void getSolnEntry(int eqnNumber, double& answer) = 0;

   //function for launching the linear solver
   virtual void launchSolver(int& solveStatus, int& iterations) = 0;
};

#endif

