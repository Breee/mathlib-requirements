#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_atan2.h"

int main()
{

  /* REQ-BL-0684:
   * The atan2 and atan2f procedures shall return +-pi/2 , if the argument y is +-Inf and the argument x has a finite value.
   */

   float x = __VERIFIER_nondet_float();
   float y = INFINITY;

   // x is finite or y is +inf
   if (isfinite_float(x) && isinf_float(y)) {

     __VERIFIER_precond_reach();

    	float res = __ieee754_atan2f(y, x);

     // x is not +-inf, y is +inf, the result shall be pi/2
    	if (res != pi_o_2) {
    		__VERIFIER_error();
    		return 1;
    	}
 	}

 	return 0;
}
