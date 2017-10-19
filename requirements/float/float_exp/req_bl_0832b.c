#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_exp.h"

int main() {

  /* REQ-BL-0832
   * The exp and expf procedures shall return 1 if the argument x is +-0.
   */

  float x = -0.0f;
  __VERIFIER_precond_reach();
  float res = __ieee754_expf(x);

  // x is -0, result shall be 1.
  if (res != 1.0f) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
