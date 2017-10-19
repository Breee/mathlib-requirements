#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_trunc.h"

int main()
{

  /* REQ-BL-1072
   * The trunc and truncf procedures shall return the argument, if the argument x is +-0 or +-Inf .
   */

  double x = 1.0/0.0; // INF
  __VERIFIER_precond_reach();
  double res = trunc_double(x);

  // x is +-inf, result shall be x.
  if (!isinf_double(res)) {
  	__VERIFIER_error();
  	return 1;
  }

	return 0;
}
