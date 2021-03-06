#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_acos.h"

int main() {

  /* REQ-BL-0480:
   * The acos and acosf procedures shall return NAN , if the argument x is +-inf
   */

  float x = -1.0f / 0.0f; // -INF
  __VERIFIER_precond_reach();
  float res = __ieee754_acosf(x);

  // x is -inf, the result shall be NAN
  if (!isnan_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
