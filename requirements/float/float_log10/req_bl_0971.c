#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_log10.h"

int main() {

  /* REQ-BL-0971
   * The log10 and log10f procedures shall return NaN , if the argument x is NaN
   * .
   */

  float x = 0.0f / 0.0f; // NAN
  __VERIFIER_precond_reach();
  float res = __ieee754_log10f(x);

  // x is NAN, result shall be NAN
  if (!isnan_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
