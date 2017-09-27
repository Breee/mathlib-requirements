#include "../includes/verify.h"
#include "../includes/math_functions_float.h"
#include "../includes/float_sin_cos_tan.h"

float tan_float(float x) {
float y[2],z=0.0;
__int32_t n,ix;

do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);


ix &= 0x7fffffff;
if(ix <= 0x3f490fda) return __kernel_tanf(x,z,1);


else if (!((ix)<0x7f800000L)) return x-x;


else {
    n = __ieee754_rem_pio2f(x,y);
    return __kernel_tanf(y[0],y[1],1-((n&1)<<1));

}
}


int main() {

  /*
   * REQ-BL-0530//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The tan and tanf procedures shall return the value of the argument if the argument is ±0 ..
   */

  float x = __VERIFIER_nondet_float();

  if (x == 0.0f || x == -0.0f) {
    __VERIFIER_precond_reach();

  	float res = tan_float(x);

    // x is +-0, the result shall be 1.0
  	if (res != x)	{
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
