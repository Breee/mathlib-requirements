#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_log.h"

int main()
{

  /* REQ-BL-0910
   * The log and logf procedures shall return -Inf if the argument x is +-0.
   */

  double x = 0.0;
  __VERIFIER_precond_reach();
  double res = __ieee754_log(x);

  // x is +-0, the result shall be -inf
  if (!isinf_double(res)) {
    __VERIFIER_error();
    return 1;
  }


	return 0;
}
