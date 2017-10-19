#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_pow.h"

int main() {

  /*
   * REQ-BL-0872//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return 1.0 if the argument y is ±0.
   */

  float x = __VERIFIER_nondet_float();
  float y = -0.0f;
  __VERIFIER_precond_reach();
  float res = __ieee754_powf(x, y);

  // result shall be 1.0
  if (res != 1.0f) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
