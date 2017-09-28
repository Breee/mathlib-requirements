#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_hypot.h"


int main() {


  /* REQ-BL-1270:
   * The hypot and hypotf procedures shall return +Inf,
   * if one of the arguments x or y is ±Inf.
   */

  float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();
  // x is not +-inf and y is not +-inf, we don't want to continue
  if (isinf_float(x) || isinf_float(y)) {
    __VERIFIER_precond_reach();

    float res = __ieee754_hypotf(x, y);

    // x is +-inf, y is any, result shall be +-inf
    if (isinf_float(x) && isinf_float(res))	{
      __VERIFIER_error();
      return 1;
    }

    // y is +-inf, x is any, result shall be +-inf
    if (isinf_float(y) && isinf_float(res))	{
      __VERIFIER_error();
      return 1;
    }
	}


	return 0;

}
