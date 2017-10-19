#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_pow.h"

int main() {

  /*
   * REQ-BL-0876//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return +0 , if |x| < 1 and the argument y
   * is +Inf .
   */

  float x = __VERIFIER_nondet_float();
  float y = 1.0f / 0.0f; // INF

  if (fabs_float(x) < 1) {

    __VERIFIER_precond_reach();

    float res = __ieee754_powf(x, y);

    // result shall be +0
    if (!(res == 0.0f && __signbit_float(res) == 0)) {
      __VERIFIER_error();
      return 1;
    }
  }

  return 0;
}
