#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_sqrt.h"

int main() {

  /*
   * REQ-BL-0720:
   * The sqrt and sqrtf procedures shall return NaN if the argument x is NaN .
   */

  float x = 0.0f / 0.0f; // NAN
  __VERIFIER_precond_reach();
  float res = __ieee754_sqrtf(x);

  // x is NAN , the result shall be NAN
  if (!isnan_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
