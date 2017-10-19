#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_ceil.h"

int main() {

  /*
   * REQ-BL-1092:
   * The ceil and ceilf procedures shall return the argument, if the argument x
   * is -+0 or -+Inf.
   */

  float x = -1.0f / 0.0f; // -INF
  __VERIFIER_precond_reach();
  float res = ceil_float(x);

  // x is -inf , the result shall be -inf
  if (!isinf_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
