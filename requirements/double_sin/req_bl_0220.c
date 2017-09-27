#include "../includes/verify.h"
#include "../includes/math_functions_double.h"
#include "../includes/double_sin_cos_tan.h"

double sin_double(double x){
  double y[2],z=0.0;
  __int32_t n,ix;
  do { ieee_double_shape_type gh_u; gh_u.value = (x); (ix) = gh_u.parts.msw; } while (0);
  ix &= 0x7fffffff;
  if(ix <= 0x3fe921fb) return __kernel_sin(x,z,0);
  else if (ix>=0x7ff00000) return x-x;
  else {
    n = __ieee754_rem_pio2(x,y);
    switch(n&3) {
     case 0: return __kernel_sin(y[0],y[1],1);
     case 1: return __kernel_cos(y[0],y[1]);
     case 2: return -__kernel_sin(y[0],y[1],1);
     default:
      return -__kernel_cos(y[0],y[1]);
    }
  }
}


int main() {

  /*
   * REQ-BL-0220//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The sin and sinf procedures shall return the value of the argument if the argument is ±0 .
   */

  double x = __VERIFIER_nondet_double();

  if (x == 0.0 || x == -0.0) {
    __VERIFIER_precond_reach();

  	double res = sin_double(x);

    // x is NAN, the result shall be NAN
  	if (res != x)	{
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
