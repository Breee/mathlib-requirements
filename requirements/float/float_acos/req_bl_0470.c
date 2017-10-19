#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_acos.h"

int main() {

  /*
   * REQ-BL-0480:
   * The acos and acosf procedures shall return NAN, if the argument x is NAN
   */

  float x = 0.0f / 0.0f; // NAN
  __VERIFIER_precond_reach();
  float res = __ieee754_acosf(x);

  // x is NAN, the result shall be NAN
  if (!isnan_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
