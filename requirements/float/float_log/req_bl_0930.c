#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_log.h"

int main() {

  /* REQ-BL-0930
   * The log and logf procedures shall return +0, if the argument x is 1.
   */

  float x = 1.0f;
  __VERIFIER_precond_reach();
  float res = __ieee754_logf(x);

  // x is  1, result shall be +0
  if (!(res == 0.0f && __signbit_float(res) == 0)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
