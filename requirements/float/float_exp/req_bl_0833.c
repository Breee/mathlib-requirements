#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_exp.h"

int main()
{

  /* REQ-BL-0833
   * The exp and expf procedures shall return +0 if the argument x is -Inf .
   */

  float x = -INFINITY;
 	float res = __ieee754_expf(x);

   // x is +inf, the result shall be x
   if (res != +0.0f) {
   	__VERIFIER_error();
   	return 1;
   }

	return 0;
}
