#include "../includes/verify.h"
#include "../includes/math_functions_float.h"

float modf_float(float x, float *iptr) {
 __int32_t i0,j0;
 __uint32_t i;
 do { ieee_float_shape_type gf_u; gf_u.value = (x); (i0) = gf_u.word; } while (0);
 j0 = ((i0>>23)&0xff)-0x7f;
 if(j0<23) {
     if(j0<0) {
         do { ieee_float_shape_type sf_u; sf_u.word = (i0&0x80000000); (*iptr) = sf_u.value; } while (0);
  return x;
     } else {
  i = (0x007fffff)>>j0;
  if((i0&i)==0) {
      __uint32_t ix;
      *iptr = x;
      do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
      do { ieee_float_shape_type sf_u; sf_u.word = (ix&0x80000000); (x) = sf_u.value; } while (0);
      return x;
  } else {
      do { ieee_float_shape_type sf_u; sf_u.word = (i0&(~i)); (*iptr) = sf_u.value; } while (0);
      return x - *iptr;
  }
     }
 } else {
     __uint32_t ix;
     *iptr = x*one;
     do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
     do { ieee_float_shape_type sf_u; sf_u.word = (ix&0x80000000); (x) = sf_u.value; } while (0);
     return x;
 }
}

int main() {

  /* REQ-BL-1211
   * The modf and modff procedures shall return ±0 and set the argument ∗iptr to +-Inf , if the argument x is +-Inf .
   */

  float x = INFINITY;
  float iptr = __VERIFIER_nondet_float();

  if (isinf_float(x)) {
    __VERIFIER_precond_reach();

    float res = modf_float(x, &iptr);
    // x is inf, *iptr is inf, result shall be -+0
  	if (isinf_float(x) && isinf_float(iptr) && res != +0.0f) {
  		__VERIFIER_error();
  		return 1;
  	}
	}


	return 0;
}
