#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_log.h"

int main()
{

  /* REQ-BL-0910
   * The log and logf procedures shall return -Inf if the argument x is +-0.
   */

  float x = __VERIFIER_nondet_float();

  if (x == 0.0f || x == -0.0f) {
    __VERIFIER_precond_reach();

    float res = __ieee754_logf(x);

    // x is +-0, the result shall be -inf
    if (!isinf_float(res)) {
      __VERIFIER_error();
      return 1;
    }
	}
	return 0;
}
