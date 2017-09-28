#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_atan2.h"


int main()
{

  /* REQ-BL-0682:
   * The atan2 and atan2f procedures shall return +-pi, if the argument +-y is finite and not 0, and the argument x is -Inf .
   */

   double x = -INFINITY;
   double y = __VERIFIER_nondet_double();

   if (isinf_double(x) && isfinite_double(y) && y > 0.0) {
     __VERIFIER_precond_reach();

     double res = __ieee754_atan2(y, x);

    // x is -inf, y > 0.0 and y != inf, the result shall be pi
     if (isinf_double(x) && y < 0.0 && isfinite_double(y) && res != pi) {
       __VERIFIER_error();
       return 1;
     }
 	}

 	return 0;
}
