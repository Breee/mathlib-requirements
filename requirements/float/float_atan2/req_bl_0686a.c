#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_atan2.h"

int main() {
  /* REQ-BL-0686:
   * The atan2 and atan2f procedures shall return +- pi/4, if the argument y is
   * +-Inf and the argument x is +Inf.
   */

  float x = 1.0f / 0.0f; // INF
  float y = 1.0f / 0.0f; // INF
  __VERIFIER_precond_reach();

  float res = __ieee754_atan2f(y, x);

  // x is +inf, y is +inf, the result shall be +pi/4
  if (res != pi_o_4) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
