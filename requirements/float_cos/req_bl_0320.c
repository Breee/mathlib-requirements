#include "../includes/verify.h"
#include "../includes/math_functions_float.h"
#include "../includes/float_sin_cos_tan.h"

float cos_float(float x) {
 float y[2],z=0.0;
 __int32_t n,ix;

 do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);


 ix &= 0x7fffffff;
 if(ix <= 0x3f490fd8) return __kernel_cosf(x,z);


 else if (!((ix)<0x7f800000L)) return x-x;


 else {
     n = __ieee754_rem_pio2f(x,y);
     switch(n&3) {
  case 0: return __kernel_cosf(y[0],y[1]);
  case 1: return -__kernel_sinf(y[0],y[1],1);
  case 2: return -__kernel_cosf(y[0],y[1]);
  default:
          return __kernel_sinf(y[0],y[1],1);
     }
 }
}

int main() {

  /*
   * REQ-BL-0320//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The cos and cosf procedures shall return 1.0 if the argument is +-0.
   */

  float x = __VERIFIER_nondet_float();

  if (x == 0.0f || x == -0.0f) {
    __VERIFIER_precond_reach();

  	float res = cos_float(x);

    // x is +-0, the result shall be 1.0
  	if (res != 1.0f)	{
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}