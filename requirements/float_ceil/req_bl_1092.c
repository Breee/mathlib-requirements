#include "../includes/verify.h"
#include "../includes/math_functions_float.h"

float ceil_float(float x) {
 __int32_t i0,j0;
 __uint32_t i,ix;
 do { ieee_float_shape_type gf_u; gf_u.value = (x); (i0) = gf_u.word; } while (0);
 ix = (i0&0x7fffffff);
 j0 = (ix>>23)-0x7f;
 if(j0<23) {
     if(j0<0) {
  if(huge+x>(float)0.0) {
      if(i0<0) {i0=0x80000000;}
      else if(!((ix)==0)) { i0=0x3f800000;}
  }
     } else {
  i = (0x007fffff)>>j0;
  if((i0&i)==0) return x;
  if(huge+x>(float)0.0) {
      if(i0>0) i0 += (0x00800000)>>j0;
      i0 &= (~i);
  }
     }
 } else {
     if(!((ix)<0x7f800000L)) return x+x;
     else return x;
 }
 do { ieee_float_shape_type sf_u; sf_u.word = (i0); (x) = sf_u.value; } while (0);
 return x;
}


int main() {

  /*
   * REQ-BL-1092:
   * The ceil and ceilf procedures shall return the argument, if the argument x is -+0 or -+Inf.
   */

  float x = __VERIFIER_nondet_float();

  // if x is not +-0 and not +-inf, we dont want to continue
  if (x == -0.0f || x == +0.0f || isinf_float(x)) {

    __VERIFIER_precond_reach();

  	float res = ceil_float(x);

    // x is -+0 or +inf , the result shall be x
  	if ((x == -0.0f || x == +0.0f || isinf_float(x)) && res != x)	{
  		__VERIFIER_error();
  		return 1;
  	}

	}

	return 0;
}
