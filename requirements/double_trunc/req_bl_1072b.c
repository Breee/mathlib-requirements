#include "../includes/verify.h"
#include "../includes/math_functions_double.h"

double trunc_double(double x) {
 int signbit;
 int msw;
 unsigned int lsw;
 int exponent_less_1023;
 do { ieee_double_shape_type ew_u; ew_u.value = (x); (msw) = ew_u.parts.msw; (lsw) = ew_u.parts.lsw; } while (0);
 signbit = msw & 0x80000000;
 exponent_less_1023 = ((msw & 0x7ff00000) >> 20) - 1023;
 if (exponent_less_1023 < 20)
   {
     if (exponent_less_1023 < 0)
       {
         do { ieee_double_shape_type iw_u; iw_u.parts.msw = (signbit); iw_u.parts.lsw = (0); (x) = iw_u.value; } while (0);
       }
     else
       {
         do { ieee_double_shape_type iw_u; iw_u.parts.msw = (signbit | (msw & ~(0x000fffff >> exponent_less_1023))); iw_u.parts.lsw = (0); (x) = iw_u.value; } while (0);
       }
   }
 else if (exponent_less_1023 > 51)
   {
     if (exponent_less_1023 == 1024)
       {
         return x + x;
       }
   }
 else
   {
     do { ieee_double_shape_type iw_u; iw_u.parts.msw = (msw); iw_u.parts.lsw = (lsw & ~(0xffffffffu >> (exponent_less_1023 - 20))); (x) = iw_u.value; } while (0);
   }
 return x;
}

int main()
{

  /* REQ-BL-1072
   * The trunc and truncf procedures shall return the argument, if the argument x is +-0 or +-Inf .
   */

  double x = __VERIFIER_nondet_double();

  if (x == 0.0 || x == -0.0) {
    __VERIFIER_precond_reach();

  	double res = trunc_double(x);

    // x is +-0, result shall be x.
  	if (res != x) {
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}