#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_atan2.h"



int main()
{
  /* REQ-BL-0686:
   * The atan2 and atan2f procedures shall return +- pi/4, if the argument y is +-Inf and the argument x is +Inf.
   */

   double x = 1.0/0.0; // INF
   double y = 1.0/0.0; // INF
   __VERIFIER_precond_reach();

   double res = __ieee754_atan2(y, x);
   // x is +inf, y is +inf, the result shall be +pi/4
   if (res != pi_o_4) {
       __VERIFIER_error();
       return 1;
  }
 	return 0;
}
