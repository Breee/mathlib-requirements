#include "../includes/verify.h"
#include "../includes/math_functions_double.h"


double modf_double(double x, double *iptr) {
 __int32_t i0,i1,j0;
 __uint32_t i;
 do { ieee_double_shape_type ew_u; ew_u.value = (x); (i0) = ew_u.parts.msw; (i1) = ew_u.parts.lsw; } while (0);
 j0 = ((i0>>20)&0x7ff)-0x3ff;
 if(j0<20) {
     if(j0<0) {
         do { ieee_double_shape_type iw_u; iw_u.parts.msw = (i0&0x80000000); iw_u.parts.lsw = (0); (*iptr) = iw_u.value; } while (0);
  return x;
     } else {
  i = (0x000fffff)>>j0;
  if(((i0&i)|i1)==0) {
      __uint32_t high;
      *iptr = x;
      do { ieee_double_shape_type gh_u; gh_u.value = (x); (high) = gh_u.parts.msw; } while (0);
      do { ieee_double_shape_type iw_u; iw_u.parts.msw = (high&0x80000000); iw_u.parts.lsw = (0); (x) = iw_u.value; } while (0);
      return x;
  } else {
      do { ieee_double_shape_type iw_u; iw_u.parts.msw = (i0&(~i)); iw_u.parts.lsw = (0); (*iptr) = iw_u.value; } while (0);
      return x - *iptr;
  }
     }
 } else if (j0>51) {
     __uint32_t high;
     *iptr = x*one;
     do { ieee_double_shape_type gh_u; gh_u.value = (x); (high) = gh_u.parts.msw; } while (0);
     do { ieee_double_shape_type iw_u; iw_u.parts.msw = (high&0x80000000); iw_u.parts.lsw = (0); (x) = iw_u.value; } while (0);
     return x;
 } else {
     i = ((__uint32_t)(0xffffffff))>>(j0-20);
     if((i1&i)==0) {
         __uint32_t high;
  *iptr = x;
  do { ieee_double_shape_type gh_u; gh_u.value = (x); (high) = gh_u.parts.msw; } while (0);
  do { ieee_double_shape_type iw_u; iw_u.parts.msw = (high&0x80000000); iw_u.parts.lsw = (0); (x) = iw_u.value; } while (0);
  return x;
     } else {
         do { ieee_double_shape_type iw_u; iw_u.parts.msw = (i0); iw_u.parts.lsw = (i1&(~i)); (*iptr) = iw_u.value; } while (0);
  return x - *iptr;
     }
 }
}

int main()
{
  double x = NAN;
  double iptr;

  /* REQ-BL-1210
   * The modf and modff procedures shall return NaN and set the argument ∗iptr to NaN, if the argument x is NaN .
   */

  if (isnan_double(x)){
    __VERIFIER_precond_reach();

  	double res = modf_double(x, &iptr);

    // x is NAN, *iptr is NAN result shall be that *iptr and x is NAN
  	if (isnan_double(x) && isnan_double(iptr) && !isnan_double(res)) {
  		__VERIFIER_error();
  		return 1;
  	}
	}
	return 0;
}