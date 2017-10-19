#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_trunc.h"

int main() {

  /* REQ-BL-1072
   * The trunc and truncf procedures shall return the argument, if the argument
   * x is +-0 or +-Inf .
   */

  float x = 1.0f / 0.0f; // INF
  __VERIFIER_precond_reach();
  float res = trunc_float(x);

  // x is inf, result shall be inf
  if (!isinf_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
