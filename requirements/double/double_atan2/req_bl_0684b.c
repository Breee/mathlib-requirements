#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_atan2.h"


int main()
{

  /* REQ-BL-0684:
   * The atan2 and atan2f procedures shall return +-pi/2 ,
   * if the argument y is +-Inf and the argument x has a finite value.
   */

   double x = __VERIFIER_nondet_double();
   double y = -1.0/0.0; // -INF

   // x is finite or y is -inf
   if (isfinite_double(x) && isinf_double(y)) {
     __VERIFIER_precond_reach();

    	double res = __ieee754_atan2(y, x);

     // x is not +-inf, y is -inf, the result shall be -pi/2
    	if (res != -pi_o_2) {
    		__VERIFIER_error();
    		return 1;
    	}
 	}

 	return 0;
}
