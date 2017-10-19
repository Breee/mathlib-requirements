#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_log10.h"

int main() {

  /* REQ-BL-0960
   * The log10 and log10f procedures shall return -Inf if the argument x is +-0.
   */

  float x = 0.0f;
  __VERIFIER_precond_reach();
  float res = __ieee754_log10f(x);

  // x is +0, the result shall be -inf
  if (!isinf_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
