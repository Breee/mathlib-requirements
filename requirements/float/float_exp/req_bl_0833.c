#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_exp.h"

int main() {

  /* REQ-BL-0833
   * The exp and expf procedures shall return +0 if the argument x is -Inf .
   */

  float x = -1.0f / 0.0f; // -INF
  float res = __ieee754_expf(x);

  // x is +inf, the result shall be +0
  if (!(res == 0.0f && __signbit_float(res) == 0)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
