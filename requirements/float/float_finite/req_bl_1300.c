#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"

int main() {

  /* REQ-BL-1300
   * The isfinite procedure shall return a non-zero value if the argument x has
   * a finite value
   * and is neither NaN nor +-Inf .
   */

  float x = __VERIFIER_nondet_float();

  // x is inf, or nan we don't want to continue
  if (isfinite_float(x) && !isnan_float(x)) {
    __VERIFIER_precond_reach();

    float res = isfinite_float(x);

    // x is not inf, is not nan, the result shall be not 0.
    if (res == 0) {
      __VERIFIER_error();
      return 1;
    }
  }
  return 0;
}
