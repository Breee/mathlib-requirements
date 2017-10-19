#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_cos.h"

int main() {

  /*
   * REQ-BL-0320//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The cos and cosf procedures shall return 1.0 if the argument is +-0.
   */

  float x = 0.0f;
  __VERIFIER_precond_reach();
  float res = cos_float(x);

  // x is +-0, the result shall be 1.0
  if (res != 1.0f) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
