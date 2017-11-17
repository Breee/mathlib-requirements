#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_hypot.h"

int main() {

  /* REQ-BL-1271:
   * The hypot and hypotf procedures shall return NaN,
   * if one of the arguments x or y is NaN and the other is not ±Inf
   */

  float x = __VERIFIER_nondet_float();
  float y = 0.0f / 0.0f; // NAN

  if (isfinite_float(x)) {
    __VERIFIER_precond_reach();
    float res = __ieee754_hypotf(x, y);
    // x is not +-inf, y is Nan, result shall be Nan
    if (!isnan_float(res)) {
      __VERIFIER_error();
      return 1;
    }
  }

  return 0;
}
