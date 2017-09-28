#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_hypot.h"

int main() {


  /* REQ-BL-1271:
   * The hypot and hypotf procedures shall return NaN,
   * if one of the arguments x or y is NaN and the other is not ±Inf
   */


  double x = __VERIFIER_nondet_double();
  double y = __VERIFIER_nondet_double();

  if((isnan_double(x) && isfinite_double(y)) || (isnan_double(y) && isfinite_double(x))) {

    __VERIFIER_precond_reach();

    double res = __ieee754_hypot(x, y);

    // x is not +-inf, y is Nan, result shall be Nan
    if (isfinite_double(x) && isnan_double(y) && !isnan_double(res))	{
      __VERIFIER_error();
      return 1;
    }

    // x is NAN, y is not +-inf, result shall be Nan
    if (isfinite_double(y) && isnan_double(x) && !isnan_double(res))	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;

}
