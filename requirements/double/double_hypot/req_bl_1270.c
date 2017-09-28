#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_hypot.h"

int main() {


  /* REQ-BL-1270:
   * The hypot and hypotf procedures shall return +Inf,
   * if one of the arguments x or y is ±Inf.
   */

  double x = __VERIFIER_nondet_double();
  double y = __VERIFIER_nondet_double();

  // x is not +-inf and y is not +-inf, we don't want to continue
  if (isinf_double(x) || isinf_double(y)) {
    __VERIFIER_precond_reach();

    double res = __ieee754_hypot(x, y);

    // x is +-inf, y is any, result shall be +-inf
    if (isinf_double(x) && isinf_double(res))	{
      __VERIFIER_error();
      return 1;
    }

    // y is +-inf, x is any, result shall be +-inf
    if (isinf_double(y) && isinf_double(res))	{
      __VERIFIER_error();
      return 1;
    }
	}


	return 0;

}
