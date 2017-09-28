#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_log.h"

int main()
{

  /* REQ-BL-0920
   * The log and logf procedures shall return NaN if the argument x is finite and less than 0 or x is -Inf.
   */

  float x = -INFINITY;

  if (isinf_float(x)) {
    __VERIFIER_precond_reach();

    float res = __ieee754_logf(x);

    // x is -inf, result shall be NAN
    if (!isnan_float(res)) {
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
