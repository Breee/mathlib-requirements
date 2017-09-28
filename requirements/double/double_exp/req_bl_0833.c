#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_exp.h"

int main()
{

  /* REQ-BL-0833
   * The exp and expf procedures shall return +0 if the argument x is -Inf .
   */

  double x = -INFINITY;
 	double res = __ieee754_exp(x);

   if (res != 0.0) {
   	__VERIFIER_error();
   	return 1;
   }

	return 0;
}
