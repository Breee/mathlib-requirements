#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_atan2.h"

int main()
{
  float x = __VERIFIER_nondet_float();
  float y = 0.0f;

  /* REQ-BL-0660:
   * The atan2 and atan2f procedures shall return +-pi, if the argument y is +-0 and the argument x < 0.
   */

   if (x < 0.0f && y == 0.0f) {

     __VERIFIER_precond_reach();

     float res = __ieee754_atan2f(y, x);

     // x is < 0, y is +0.0f, the result shall be +pi
     if (res != pi) {
       __VERIFIER_error();
       return 1;
     }


 	}

 	return 0;
}
