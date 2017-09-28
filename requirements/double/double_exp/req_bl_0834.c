#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_exp.h"

int main()
{

  /* REQ-BL-0834
   * The exp and expf procedures shall return the argument if the argument x is +Inf .
   */

  double x = INFINITY;
	double res = __ieee754_exp(x);

  // x is +inf, the result shall be x
  if (res != x) {
  	__VERIFIER_error();
  	return 1;
  }

	return 0;
}
