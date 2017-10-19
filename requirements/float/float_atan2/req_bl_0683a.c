#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_atan2.h"

int main() {

  /*
   * REQ-BL-0683//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The atan2 and atan2f procedures shall return ±0 ,
   * if the argument ± y is finite and not 0, and the argument x is +Inf .
   */

  float x = 1.0f / 0.0f; // INF
  float y = __VERIFIER_nondet_float();

  if (isfinite_float(y) && y < 0.0f) {
    __VERIFIER_precond_reach();

    float res = __ieee754_atan2f(y, x);

    // x is -inf, y < 0.0 and y != -inf, the result shall be -0.0
    if (!(res == -0.0f && __signbit_float(res) == 1)) {
      __VERIFIER_error();
      return 1;
    }
  }

  return 0;
}
