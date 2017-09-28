#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_trunc.h"

int main()
{

  /* REQ-BL-1072
   * The trunc and truncf procedures shall return the argument, if the argument x is +-0 or +-Inf .
   */

  float x = __VERIFIER_nondet_float();
  // x is not +-inf and not +-0, we don't want to continue
  if (isinf_float(x) || x == +0.0f || x == -0.0f) {
    __VERIFIER_precond_reach();

  	float res = trunc_float(x);

    // x is +-0 or +-inf, result shall be x.
  	if (res != x) {
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
