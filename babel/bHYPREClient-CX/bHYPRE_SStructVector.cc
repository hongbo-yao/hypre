// 
// File:          bHYPRE_SStructVector.cc
// Symbol:        bHYPRE.SStructVector-v1.0.0
// Symbol Type:   class
// Babel Version: 0.10.12
// Description:   Client-side glue code for bHYPRE.SStructVector
// 
// WARNING: Automatically generated; changes will be lost
// 
// babel-version = 0.10.12
// 

#ifndef included_bHYPRE_SStructVector_hh
#include "bHYPRE_SStructVector.hh"
#endif
#ifndef included_sidl_BaseInterface_hh
#include "sidl_BaseInterface.hh"
#endif
#ifndef included_sidl_BaseClass_hh
#include "sidl_BaseClass.hh"
#endif
#include "sidl_String.h"
#include "babel_config.h"
#ifdef SIDL_DYNAMIC_LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include "sidl_Loader.hh"
#include "sidl_DLL.hh"
#endif
// 
// Includes for all method dependencies.
// 
#ifndef included_bHYPRE_MPICommunicator_hh
#include "bHYPRE_MPICommunicator.hh"
#endif
#ifndef included_bHYPRE_SStructGrid_hh
#include "bHYPRE_SStructGrid.hh"
#endif
#ifndef included_bHYPRE_SStructVector_hh
#include "bHYPRE_SStructVector.hh"
#endif
#ifndef included_bHYPRE_Vector_hh
#include "bHYPRE_Vector.hh"
#endif
#ifndef included_sidl_BaseInterface_hh
#include "sidl_BaseInterface.hh"
#endif
#ifndef included_sidl_ClassInfo_hh
#include "sidl_ClassInfo.hh"
#endif


//////////////////////////////////////////////////
// 
// User Defined Methods
// 

/**
 * user defined static method
 */
::ucxx::bHYPRE::SStructVector
ucxx::bHYPRE::SStructVector::Create( /* in */::ucxx::bHYPRE::MPICommunicator 
  mpi_comm, /* in */::ucxx::bHYPRE::SStructGrid grid )
throw ()

{
  ::ucxx::bHYPRE::SStructVector _result;
  struct bHYPRE_MPICommunicator__object* _local_mpi_comm = mpi_comm._get_ior();
  struct bHYPRE_SStructGrid__object* _local_grid = grid._get_ior();
  /*pack args to dispatch to ior*/
  _result = ::ucxx::bHYPRE::SStructVector( ( _get_sepv()->f_Create)( /* in */ 
    _local_mpi_comm, /* in */ _local_grid ), false);
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Return true if and only if <code>obj</code> refers to the same
 * object as this object.
 */
bool
ucxx::bHYPRE::SStructVector::isSame( /* in */::ucxx::sidl::BaseInterface iobj )
throw ()

{
  bool _result;
  ior_t* loc_self = _get_ior();
  sidl_bool _local_result;
  struct sidl_BaseInterface__object* _local_iobj = reinterpret_cast< struct 
    sidl_BaseInterface__object* > ( iobj._get_ior() ? ((*((reinterpret_cast< 
    struct sidl_BaseInterface__object * > 
    (iobj._get_ior()))->d_epv->f__cast))((reinterpret_cast< struct 
    sidl_BaseInterface__object * > (iobj._get_ior()))->d_object,
    "sidl.BaseInterface")) : 0);
  /*pack args to dispatch to ior*/
  _local_result = (*(loc_self->d_epv->f_isSame))(loc_self,
    /* in */ _local_iobj );
  /*dispatch to ior*/
  _result = _local_result;
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Check whether the object can support the specified interface or
 * class.  If the <code>sidl</code> type name in <code>name</code>
 * is supported, then a reference to that object is returned with the
 * reference count incremented.  The callee will be responsible for
 * calling <code>deleteRef</code> on the returned object.  If
 * the specified type is not supported, then a null reference is
 * returned.
 */
::ucxx::sidl::BaseInterface
ucxx::bHYPRE::SStructVector::queryInt( /* in */const ::std::string& name )
throw ()

{
  ::ucxx::sidl::BaseInterface _result;
  ior_t* loc_self = _get_ior();
  /*pack args to dispatch to ior*/
  _result = ::ucxx::sidl::BaseInterface( 
    (*(loc_self->d_epv->f_queryInt))(loc_self, /* in */ name.c_str() ), false);
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Return whether this object is an instance of the specified type.
 * The string name must be the <code>sidl</code> type name.  This
 * routine will return <code>true</code> if and only if a cast to
 * the string type name would succeed.
 */
bool
ucxx::bHYPRE::SStructVector::isType( /* in */const ::std::string& name )
throw ()

{
  bool _result;
  ior_t* loc_self = _get_ior();
  sidl_bool _local_result;
  /*pack args to dispatch to ior*/
  _local_result = (*(loc_self->d_epv->f_isType))(loc_self,
    /* in */ name.c_str() );
  /*dispatch to ior*/
  _result = _local_result;
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Return the meta-data about the class implementing this interface.
 */
::ucxx::sidl::ClassInfo
ucxx::bHYPRE::SStructVector::getClassInfo(  )
throw ()

{
  ::ucxx::sidl::ClassInfo _result;
  ior_t* loc_self = _get_ior();
  /*pack args to dispatch to ior*/
  _result = ::ucxx::sidl::ClassInfo( 
    (*(loc_self->d_epv->f_getClassInfo))(loc_self ), false);
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Set the MPI Communicator.  DEPRECATED, Use Create()
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::SetCommunicator( /* in 
  */::ucxx::bHYPRE::MPICommunicator mpi_comm )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  struct bHYPRE_MPICommunicator__object* _local_mpi_comm = mpi_comm._get_ior();
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_SetCommunicator))(loc_self,
    /* in */ _local_mpi_comm );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 *  A semi-structured matrix or vector contains a Struct or IJ matrix
 *  or vector.  GetObject returns it.
 * The returned type is a sidl.BaseInterface.
 * QueryInterface or Cast must be used on the returned object to
 * convert it into a known type.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::GetObject( /* out */::ucxx::sidl::BaseInterface& A 
  )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  struct sidl_BaseInterface__object* _local_A;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_GetObject))(loc_self, /* out */ &_local_A );
  /*dispatch to ior*/
  if ( A._not_nil() ) {
    A.deleteRef();
  }
  A._set_ior( _local_A);
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Set the vector grid.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::SetGrid( /* in */::ucxx::bHYPRE::SStructGrid grid )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  struct bHYPRE_SStructGrid__object* _local_grid = grid._get_ior();
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_SetGrid))(loc_self, /* in */ _local_grid );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Set vector coefficients index by index.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * If the vector is complex, then {\tt value} consists of a pair
 * of doubles representing the real and imaginary parts of the
 * complex value.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::SetValues( /* in */int32_t part,
  /* in rarray[dim] */int32_t* index, /* in */int32_t dim, /* in */int32_t var,
  /* in */double value )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  int32_t index_lower[1], index_upper[1], index_stride[1];
  struct sidl_int__array index_real;
  struct sidl_int__array *index_tmp = &index_real;
  index_upper[0] = dim-1;
  sidl_int__array_init(index, index_tmp, 1, index_lower, index_upper,
    index_stride);
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_SetValues))(loc_self, /* in */ part,
    /* in rarray[dim] */ index_tmp, /* in */ var, /* in */ value );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Set vector coefficients index by index.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * If the vector is complex, then {\tt value} consists of a pair
 * of doubles representing the real and imaginary parts of the
 * complex value.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::SetValues( /* in */int32_t part,
  /* in rarray[dim] */::ucxx::sidl::array<int32_t> index, /* in */int32_t var,
  /* in */double value )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_SetValues))(loc_self, /* in */ part,
    /* in rarray[dim] */ index._get_ior(), /* in */ var, /* in */ value );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Set vector coefficients a box at a time.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * If the vector is complex, then {\tt values} consists of pairs
 * of doubles representing the real and imaginary parts of each
 * complex value.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::SetBoxValues( /* in */int32_t part,
  /* in rarray[dim] */int32_t* ilower, /* in rarray[dim] */int32_t* iupper,
  /* in */int32_t dim, /* in */int32_t var,
  /* in rarray[nvalues] */double* values, /* in */int32_t nvalues )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  int32_t ilower_lower[1], ilower_upper[1], ilower_stride[1];
  struct sidl_int__array ilower_real;
  struct sidl_int__array *ilower_tmp = &ilower_real;
  ilower_upper[0] = dim-1;
  sidl_int__array_init(ilower, ilower_tmp, 1, ilower_lower, ilower_upper,
    ilower_stride);
  int32_t iupper_lower[1], iupper_upper[1], iupper_stride[1];
  struct sidl_int__array iupper_real;
  struct sidl_int__array *iupper_tmp = &iupper_real;
  iupper_upper[0] = dim-1;
  sidl_int__array_init(iupper, iupper_tmp, 1, iupper_lower, iupper_upper,
    iupper_stride);
  int32_t values_lower[1], values_upper[1], values_stride[1];
  struct sidl_double__array values_real;
  struct sidl_double__array *values_tmp = &values_real;
  values_upper[0] = nvalues-1;
  sidl_double__array_init(values, values_tmp, 1, values_lower, values_upper,
    values_stride);
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_SetBoxValues))(loc_self, /* in */ part,
    /* in rarray[dim] */ ilower_tmp, /* in rarray[dim] */ iupper_tmp,
    /* in */ var, /* in rarray[nvalues] */ values_tmp );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Set vector coefficients a box at a time.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * If the vector is complex, then {\tt values} consists of pairs
 * of doubles representing the real and imaginary parts of each
 * complex value.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::SetBoxValues( /* in */int32_t part,
  /* in rarray[dim] */::ucxx::sidl::array<int32_t> ilower,
  /* in rarray[dim] */::ucxx::sidl::array<int32_t> iupper, /* in */int32_t var,
  /* in rarray[nvalues] */::ucxx::sidl::array<double> values )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_SetBoxValues))(loc_self, /* in */ part,
    /* in rarray[dim] */ ilower._get_ior(),
    /* in rarray[dim] */ iupper._get_ior(), /* in */ var,
    /* in rarray[nvalues] */ values._get_ior() );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Set vector coefficients index by index.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * If the vector is complex, then {\tt value} consists of a pair
 * of doubles representing the real and imaginary parts of the
 * complex value.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::AddToValues( /* in */int32_t part,
  /* in rarray[dim] */int32_t* index, /* in */int32_t dim, /* in */int32_t var,
  /* in */double value )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  int32_t index_lower[1], index_upper[1], index_stride[1];
  struct sidl_int__array index_real;
  struct sidl_int__array *index_tmp = &index_real;
  index_upper[0] = dim-1;
  sidl_int__array_init(index, index_tmp, 1, index_lower, index_upper,
    index_stride);
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_AddToValues))(loc_self, /* in */ part,
    /* in rarray[dim] */ index_tmp, /* in */ var, /* in */ value );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Set vector coefficients index by index.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * If the vector is complex, then {\tt value} consists of a pair
 * of doubles representing the real and imaginary parts of the
 * complex value.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::AddToValues( /* in */int32_t part,
  /* in rarray[dim] */::ucxx::sidl::array<int32_t> index, /* in */int32_t var,
  /* in */double value )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_AddToValues))(loc_self, /* in */ part,
    /* in rarray[dim] */ index._get_ior(), /* in */ var, /* in */ value );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Set vector coefficients a box at a time.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * If the vector is complex, then {\tt values} consists of pairs
 * of doubles representing the real and imaginary parts of each
 * complex value.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::AddToBoxValues( /* in */int32_t part,
  /* in rarray[dim] */int32_t* ilower, /* in rarray[dim] */int32_t* iupper,
  /* in */int32_t dim, /* in */int32_t var,
  /* in rarray[nvalues] */double* values, /* in */int32_t nvalues )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  int32_t ilower_lower[1], ilower_upper[1], ilower_stride[1];
  struct sidl_int__array ilower_real;
  struct sidl_int__array *ilower_tmp = &ilower_real;
  ilower_upper[0] = dim-1;
  sidl_int__array_init(ilower, ilower_tmp, 1, ilower_lower, ilower_upper,
    ilower_stride);
  int32_t iupper_lower[1], iupper_upper[1], iupper_stride[1];
  struct sidl_int__array iupper_real;
  struct sidl_int__array *iupper_tmp = &iupper_real;
  iupper_upper[0] = dim-1;
  sidl_int__array_init(iupper, iupper_tmp, 1, iupper_lower, iupper_upper,
    iupper_stride);
  int32_t values_lower[1], values_upper[1], values_stride[1];
  struct sidl_double__array values_real;
  struct sidl_double__array *values_tmp = &values_real;
  values_upper[0] = nvalues-1;
  sidl_double__array_init(values, values_tmp, 1, values_lower, values_upper,
    values_stride);
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_AddToBoxValues))(loc_self, /* in */ part,
    /* in rarray[dim] */ ilower_tmp, /* in rarray[dim] */ iupper_tmp,
    /* in */ var, /* in rarray[nvalues] */ values_tmp );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Set vector coefficients a box at a time.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * If the vector is complex, then {\tt values} consists of pairs
 * of doubles representing the real and imaginary parts of each
 * complex value.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::AddToBoxValues( /* in */int32_t part,
  /* in rarray[dim] */::ucxx::sidl::array<int32_t> ilower,
  /* in rarray[dim] */::ucxx::sidl::array<int32_t> iupper, /* in */int32_t var,
  /* in rarray[nvalues] */::ucxx::sidl::array<double> values )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_AddToBoxValues))(loc_self, /* in */ part,
    /* in rarray[dim] */ ilower._get_ior(),
    /* in rarray[dim] */ iupper._get_ior(), /* in */ var,
    /* in rarray[nvalues] */ values._get_ior() );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Get vector coefficients index by index.
 * 
 * NOTE: Users may only get values on processes that own the
 * associated variables.
 * 
 * If the vector is complex, then {\tt value} consists of a pair
 * of doubles representing the real and imaginary parts of the
 * complex value.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::GetValues( /* in */int32_t part,
  /* in rarray[dim] */int32_t* index, /* in */int32_t dim, /* in */int32_t var,
  /* out */double& value )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  int32_t index_lower[1], index_upper[1], index_stride[1];
  struct sidl_int__array index_real;
  struct sidl_int__array *index_tmp = &index_real;
  index_upper[0] = dim-1;
  sidl_int__array_init(index, index_tmp, 1, index_lower, index_upper,
    index_stride);
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_GetValues))(loc_self, /* in */ part,
    /* in rarray[dim] */ index_tmp, /* in */ var, /* out */ &value );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Get vector coefficients index by index.
 * 
 * NOTE: Users may only get values on processes that own the
 * associated variables.
 * 
 * If the vector is complex, then {\tt value} consists of a pair
 * of doubles representing the real and imaginary parts of the
 * complex value.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::GetValues( /* in */int32_t part,
  /* in rarray[dim] */::ucxx::sidl::array<int32_t> index, /* in */int32_t var,
  /* out */double& value )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_GetValues))(loc_self, /* in */ part,
    /* in rarray[dim] */ index._get_ior(), /* in */ var, /* out */ &value );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Get vector coefficients a box at a time.
 * 
 * NOTE: Users may only get values on processes that own the
 * associated variables.
 * 
 * If the vector is complex, then {\tt values} consists of pairs
 * of doubles representing the real and imaginary parts of each
 * complex value.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::GetBoxValues( /* in */int32_t part,
  /* in rarray[dim] */int32_t* ilower, /* in rarray[dim] */int32_t* iupper,
  /* in */int32_t dim, /* in */int32_t var,
  /* inout rarray[nvalues] */double* values, /* in */int32_t nvalues )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  int32_t ilower_lower[1], ilower_upper[1], ilower_stride[1];
  struct sidl_int__array ilower_real;
  struct sidl_int__array *ilower_tmp = &ilower_real;
  ilower_upper[0] = dim-1;
  sidl_int__array_init(ilower, ilower_tmp, 1, ilower_lower, ilower_upper,
    ilower_stride);
  int32_t iupper_lower[1], iupper_upper[1], iupper_stride[1];
  struct sidl_int__array iupper_real;
  struct sidl_int__array *iupper_tmp = &iupper_real;
  iupper_upper[0] = dim-1;
  sidl_int__array_init(iupper, iupper_tmp, 1, iupper_lower, iupper_upper,
    iupper_stride);
  int32_t values_lower[1], values_upper[1], values_stride[1];
  struct sidl_double__array values_real;
  struct sidl_double__array *values_tmp = &values_real;
  values_upper[0] = nvalues-1;
  sidl_double__array_init(values, values_tmp, 1, values_lower, values_upper,
    values_stride);
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_GetBoxValues))(loc_self, /* in */ part,
    /* in rarray[dim] */ ilower_tmp, /* in rarray[dim] */ iupper_tmp,
    /* in */ var, /* inout rarray[nvalues] */ &values_tmp );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Get vector coefficients a box at a time.
 * 
 * NOTE: Users may only get values on processes that own the
 * associated variables.
 * 
 * If the vector is complex, then {\tt values} consists of pairs
 * of doubles representing the real and imaginary parts of each
 * complex value.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::GetBoxValues( /* in */int32_t part,
  /* in rarray[dim] */::ucxx::sidl::array<int32_t> ilower,
  /* in rarray[dim] */::ucxx::sidl::array<int32_t> iupper, /* in */int32_t var,
  /* inout rarray[nvalues] */::ucxx::sidl::array<double>& values )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  if (values) {
    values.addRef();
  }
  struct sidl_double__array* _local_values = values._get_ior();
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_GetBoxValues))(loc_self, /* in */ part,
    /* in rarray[dim] */ ilower._get_ior(),
    /* in rarray[dim] */ iupper._get_ior(), /* in */ var,
    /* inout rarray[nvalues] */ &_local_values );
  /*dispatch to ior*/
  values._set_ior(_local_values);
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Print the vector to file.  This is mainly for debugging
 * purposes.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::Print( /* in */const ::std::string& filename,
  /* in */int32_t all )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_Print))(loc_self, /* in */ filename.c_str(),
    /* in */ all );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Copy data from x into {\tt self}.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::Copy( /* in */::ucxx::bHYPRE::Vector x )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  struct bHYPRE_Vector__object* _local_x = reinterpret_cast< struct 
    bHYPRE_Vector__object* > ( x._get_ior() ? ((*((reinterpret_cast< struct 
    sidl_BaseInterface__object * > 
    (x._get_ior()))->d_epv->f__cast))((reinterpret_cast< struct 
    sidl_BaseInterface__object * > (x._get_ior()))->d_object,
    "bHYPRE.Vector")) : 0);
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_Copy))(loc_self, /* in */ _local_x );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Create an {\tt x} compatible with {\tt self}.
 * The new vector's data is not specified.
 * 
 * NOTE: When this method is used in an inherited class, the
 * cloned {\tt Vector} object can be cast to an object with the
 * inherited class type.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::Clone( /* out */::ucxx::bHYPRE::Vector& x )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  struct bHYPRE_Vector__object* _local_x;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_Clone))(loc_self, /* out */ &_local_x );
  /*dispatch to ior*/
  if ( x._not_nil() ) {
    x.deleteRef();
  }
  x._set_ior( _local_x);
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Compute {\tt d}, the inner-product of {\tt self} and {\tt x}.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::Dot( /* in */::ucxx::bHYPRE::Vector x,
  /* out */double& d )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  struct bHYPRE_Vector__object* _local_x = reinterpret_cast< struct 
    bHYPRE_Vector__object* > ( x._get_ior() ? ((*((reinterpret_cast< struct 
    sidl_BaseInterface__object * > 
    (x._get_ior()))->d_epv->f__cast))((reinterpret_cast< struct 
    sidl_BaseInterface__object * > (x._get_ior()))->d_object,
    "bHYPRE.Vector")) : 0);
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_Dot))(loc_self, /* in */ _local_x,
    /* out */ &d );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Add {\tt a}*{\tt x} to {\tt self}.
 * 
 */
int32_t
ucxx::bHYPRE::SStructVector::Axpy( /* in */double a,
  /* in */::ucxx::bHYPRE::Vector x )
throw ()

{
  int32_t _result;
  ior_t* loc_self = _get_ior();
  struct bHYPRE_Vector__object* _local_x = reinterpret_cast< struct 
    bHYPRE_Vector__object* > ( x._get_ior() ? ((*((reinterpret_cast< struct 
    sidl_BaseInterface__object * > 
    (x._get_ior()))->d_epv->f__cast))((reinterpret_cast< struct 
    sidl_BaseInterface__object * > (x._get_ior()))->d_object,
    "bHYPRE.Vector")) : 0);
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_Axpy))(loc_self, /* in */ a,
    /* in */ _local_x );
  /*dispatch to ior*/
  /*unpack results and cleanup*/
  return _result;
}



//////////////////////////////////////////////////
// 
// End User Defined Methods
// (everything else in this file is specific to
//  Babel's C++ bindings)
// 

// static constructor
::ucxx::bHYPRE::SStructVector
ucxx::bHYPRE::SStructVector::_create() {
  ::ucxx::bHYPRE::SStructVector self( (*_get_ext()->createObject)(), false );
  return self;
}

// copy constructor
ucxx::bHYPRE::SStructVector::SStructVector ( const 
  ::ucxx::bHYPRE::SStructVector& original ) {
  d_self = original._cast("bHYPRE.SStructVector");
  d_weak_reference = original.d_weak_reference;
  if (d_self != 0 ) {
    addRef();
  }
}

// assignment operator
::ucxx::bHYPRE::SStructVector&
ucxx::bHYPRE::SStructVector::operator=( const ::ucxx::bHYPRE::SStructVector& 
  rhs ) {
  if ( d_self != rhs.d_self ) {
    if ( d_self != 0 ) {
      deleteRef();
    }
    d_self = rhs._cast("bHYPRE.SStructVector");
    d_weak_reference = rhs.d_weak_reference;
    if ( d_self != 0 ) {
      addRef();
    }
  }
  return *this;
}

// conversion from ior to C++ class
ucxx::bHYPRE::SStructVector::SStructVector ( 
  ::ucxx::bHYPRE::SStructVector::ior_t* ior ) 
   : StubBase(reinterpret_cast< void*>(ior)) { }

// Alternate constructor: does not call addRef()
// (sets d_weak_reference=isWeak)
// For internal use by Impls (fixes bug#275)
ucxx::bHYPRE::SStructVector::SStructVector ( 
  ::ucxx::bHYPRE::SStructVector::ior_t* ior, bool isWeak ) : 
StubBase(reinterpret_cast< void*>(ior), isWeak){ 
}

// protected method that implements casting
void* ucxx::bHYPRE::SStructVector::_cast(const char* type) const
{
  ior_t* loc_self = reinterpret_cast< ior_t*>(this->d_self);
  void* ptr = 0;
  if ( loc_self != 0 ) {
    ptr = reinterpret_cast< void*>((*loc_self->d_epv->f__cast)(loc_self, type));
  }
  return ptr;
}

// Static data type
const ::ucxx::bHYPRE::SStructVector::ext_t * ucxx::bHYPRE::SStructVector::s_ext 
  = 0;

// private static method to get static data type
const ::ucxx::bHYPRE::SStructVector::ext_t *
ucxx::bHYPRE::SStructVector::_get_ext()
  throw ( ::ucxx::sidl::NullIORException)
{
  if (! s_ext ) {
#ifdef SIDL_STATIC_LIBRARY
    s_ext = bHYPRE_SStructVector__externals();
#else
    s_ext = (struct 
      bHYPRE_SStructVector__external*)sidl_dynamicLoadIOR(
      "bHYPRE.SStructVector","bHYPRE_SStructVector__externals") ;
#endif
  }
  return s_ext;
}
