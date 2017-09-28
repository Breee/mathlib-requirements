#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_atan2.h"

int main() {

  /* REQ-BL-0670:
   * The atan2 and atan2f procedures shall return NaN if any argument is NaN.
   */

   float x = __VERIFIER_nondet_float();
   float y = __VERIFIER_nondet_float();

   if (isnan_float(x) || isnan_float(y)) {

     __VERIFIER_precond_reach();

    	float res = __ieee754_atan2f(y, x);

     // x is NAN, y is any or vice versa, the result shall be NAN
     if ((isnan_float(x) || isnan_float(y)) && !isnan_float(res)) {
    		__VERIFIER_error();
    		return 1;
    	}
 	}

 	return 0;
}
