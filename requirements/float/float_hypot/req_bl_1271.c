#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_hypot.h"

int main() {

  float x = __VERIFIER_nondet_float();
	float y = __VERIFIER_nondet_float();

  /* REQ-BL-1271:
   * The hypot and hypotf procedures shall return NaN,
   * if one of the arguments x or y is NaN and the other is not ±Inf
   */


  if((isnan_float(x) && isfinite_float(y)) || (isnan_float(y) && isfinite_float(x))) {

    __VERIFIER_precond_reach();

    float res = __ieee754_hypotf(x, y);

    // x is not +-inf, y is Nan, result shall be Nan
    if (isfinite_float(x) && isnan_float(y) && !isnan_float(res))	{
      __VERIFIER_error();
      return 1;
    }

    // x is NAN, y is not +-inf, result shall be Nan
    if (isfinite_float(y) && isnan_float(x) && !isnan_float(res))	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;

}
