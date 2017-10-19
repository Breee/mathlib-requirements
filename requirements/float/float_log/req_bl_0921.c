#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_log.h"

int main() {

  /* REQ-BL-0921
   * The log and logf procedures shall return NaN , if the argument x is NaN .
   */

  float x = 0.0f / 0.0f; // NAN
  __VERIFIER_precond_reach();
  float res = __ieee754_logf(x);

  // x is NAN, result shall be NAN
  if (!isnan_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
