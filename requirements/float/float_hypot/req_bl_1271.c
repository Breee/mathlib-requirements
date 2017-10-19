#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_hypot.h"

int main() {

  /* REQ-BL-1271:
  * The hypot and hypotf procedures shall return NaN,
  * if one of the arguments x or y is NaN and the other is not ±Inf
  */

  float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();

  if ((isnan_float(x) && isfinite_float(y)) ||
      (isnan_float(y) && isfinite_float(x))) {

    __VERIFIER_precond_reach();

    float res = __ieee754_hypotf(x, y);

    // result shall be NAN
    if (!isnan_float(res)) {
      __VERIFIER_error();
      return 1;
    }
  }

  return 0;
}
