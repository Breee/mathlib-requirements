#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_log.h"

int main()
{

  /* REQ-BL-0931
   * The log and logf procedures shall return +Inf, if the argument x is +Inf .
   */

  double x = INFINITY;

  if (isinf_double(x)) {
    __VERIFIER_precond_reach();

    double res = __ieee754_log(x);

    // x is +inf, result shall be +inf
    if (!isinf_double(res)) {
      __VERIFIER_error();
      return 1;
    }
	}


	return 0;
}
