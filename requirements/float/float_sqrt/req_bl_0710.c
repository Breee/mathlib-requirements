#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_sqrt.h"

int main() {

  /*
   * REQ-BL-0710:
   * The sqrt and sqrtf procedures shall return NaN, if the argument x < -0.
   */

  float x = __VERIFIER_nondet_float();
  if (x < -0.0f) {
    __VERIFIER_precond_reach();

    float res = __ieee754_sqrtf(x);

    // x is -0 , the result shall be NAN
    if (!isnan_float(res)) {
      __VERIFIER_error();
      return 1;
    }
  }

  return 0;
}
