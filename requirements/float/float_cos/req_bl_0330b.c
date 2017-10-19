#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_cos.h"

int main() {

  /*
   * REQ-BL-0330//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The cos and cosf procedures shall return NaN , if the argument is +-Inf .
   */

  float x = -1.0f / 0.0f; // -INF
  __VERIFIER_precond_reach();
  float res = cos_float(x);

  // x is -INF, the result shall be NAN
  if (!isnan_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
