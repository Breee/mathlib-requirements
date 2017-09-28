#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_atan2.h"

int main()
{

  /* REQ-BL-0680:
   * The atan2 and atan2f procedures shall return +-pi, if the argument y is +-0 and the argument x is -0.
   */

   double x = -0.0;
   double y = 0.0;

   if (x == -0.0 && y == 0.0) {
     __VERIFIER_precond_reach();

     double res = __ieee754_atan2(y, x);

     // x is -0, y is -0, the result shall be -pi
     if (res != pi) {
       __VERIFIER_error();
       return 1;
     }
 	}

 	return 0;
}
