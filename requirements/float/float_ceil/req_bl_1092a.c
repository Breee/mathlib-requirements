#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_ceil.h"

int main() {

  /*
   * REQ-BL-1092:
   * The ceil and ceilf procedures shall return the argument, if the argument x
   * is -+0 or -+Inf.
   */

  float x = -0.0f;
  __VERIFIER_precond_reach();
  float res = ceil_float(x);

  // x is -0  the result shall be -0
  if (!(res == -0.0f && __signbit_float(res) == 1)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
