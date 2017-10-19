#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_log.h"

int main() {

  /* REQ-BL-0931
   * The log and logf procedures shall return +Inf, if the argument x is +Inf .
   */

  float x = 1.0f / 0.0f; // INF
  __VERIFIER_precond_reach();

  float res = __ieee754_logf(x);

  // x is +inf, result shall be +inf
  if (!isinf_float(res)) {
    __VERIFIER_error();
    return 1;
  }
  return 0;
}
