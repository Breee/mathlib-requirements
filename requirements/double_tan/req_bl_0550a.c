#include "../includes/verify.h"
#include "../includes/math_functions_double.h"
#include "../includes/double_sin_cos_tan.h"

double tan_double(double x) {
double y[2],z=0.0;
__int32_t n,ix;


do { ieee_double_shape_type gh_u; gh_u.value = (x); (ix) = gh_u.parts.msw; } while (0);


ix &= 0x7fffffff;
if(ix <= 0x3fe921fb) return __kernel_tan(x,z,1);


else if (ix>=0x7ff00000) return x-x;


else {
    n = __ieee754_rem_pio2(x,y);
    return __kernel_tan(y[0],y[1],1-((n&1)<<1));

}
}


int main() {

  /*
   * REQ-BL-0550//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
The tan and tanf procedures shall return NaN , if the argument is ±Inf .
   */

  double x = INFINITY;

  if (isinf_double(x)) {
    __VERIFIER_precond_reach();

  	double res = tan_double(x);

    // x is +INF, the result shall be NAN
  	if (!isnan_double(res))	{
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
