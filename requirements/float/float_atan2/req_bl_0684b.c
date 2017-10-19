#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_atan2.h"

int main() {

  /* REQ-BL-0684:
   * The atan2 and atan2f procedures shall return +-pi/2 ,
   * if the argument y is +-Inf and the argument x has a finite value.
   */

  float x = __VERIFIER_nondet_float();
  float y = -1.0f / 0.0f; // -INF

  if (isfinite_float(x)) {
    __VERIFIER_precond_reach();

    float res = __ieee754_atan2f(y, x);

    // x is not +-inf, y is -inf, the result shall be -pi/2
    if (res != -pi_o_2) {
      __VERIFIER_error();
      return 1;
    }
  }

  return 0;
}
