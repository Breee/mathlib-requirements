#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_atan2.h"

int main() {

  /* REQ-BL-0670:
   * The atan2 and atan2f procedures shall return NaN if any argument is NaN.
   */

   double x = __VERIFIER_nondet_double();
   double y = __VERIFIER_nondet_double();

   if (isnan_double(x) || isnan_double(y)) {

     __VERIFIER_precond_reach();

    	double res = __ieee754_atan2(y, x);

     // x is NAN, y is any or vice versa, the result shall be NAN
     if ((isnan_double(x) || isnan_double(y)) && !isnan_double(res)) {
    		__VERIFIER_error();
    		return 1;
    	}
 	}

 	return 0;
}
