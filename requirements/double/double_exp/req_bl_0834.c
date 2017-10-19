#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_exp.h"

int main()
{

  /* REQ-BL-0834
   * The exp and expf procedures shall return the argument if the argument x is +Inf .
   */

  double x = 1.0/0.0; // INF
  __VERIFIER_precond_reach();
	double res = __ieee754_exp(x);

  // x is +inf, the result shall be +inf
  if (!isinf_double(x)) {
  	__VERIFIER_error();
  	return 1;
  }

	return 0;
}
