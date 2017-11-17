#include "../../includes/math_functions_double.h"
#include "../../includes/verify.h"
#include "double_hypot.h"

int main() {

  /* REQ-BL-1271:
   * The hypot and hypotf procedures shall return NaN,
   * if one of the arguments x or y is NaN and the other is not ±Inf
   */

  double x = 0.0 / 0.0; // NAN
  double y = __VERIFIER_nondet_double();

  if (isfinite_double(y)) {
    __VERIFIER_precond_reach();
    double res = __ieee754_hypot(x, y);
    // y is not +-inf, x is Nan, result shall be Nan
    if (!isnan_double(res)) {
      __VERIFIER_error();
      return 1;
    }
  }

  return 0;
}
