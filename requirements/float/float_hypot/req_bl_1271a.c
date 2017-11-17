#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_hypot.h"

int main() {

  /* REQ-BL-1271:
   * The hypot and hypotf procedures shall return NaN,
   * if one of the arguments x or y is NaN and the other is not ±Inf
   */

  float x = 0.0f / 0.0f; // NAN
  float y = __VERIFIER_nondet_float();

  if (isfinite_float(y)) {
    __VERIFIER_precond_reach();
    float res = __ieee754_hypotf(x, y);
    // y is not +-inf, x is Nan, result shall be Nan
    if (!isnan_float(res)) {
      __VERIFIER_error();
      return 1;
    }
  }

  return 0;
}
