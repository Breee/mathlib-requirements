#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_atan2.h"

int main()
{
  float x = 0.0f;
  float y = __VERIFIER_nondet_float();

  /* REQ-BL-0662:
   * The atan2 and atan2f procedures shall return -pi/2 , if the argument y is < 0 and the argument x is +-0 .
   */

   if (x == 0.0f && y < 0.0f) {
     __VERIFIER_precond_reach();

     float res = __ieee754_atan2f(y, x);

      // x is +-0, y is < 0, the result shall be -pi/2
     if (res != -pi_o_2) {
       __VERIFIER_error();
       return 1;
     }
 	}

 	return 0;
}
