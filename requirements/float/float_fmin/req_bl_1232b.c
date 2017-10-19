#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_fmin.h"

int main() {

  /*
   * REQ-BL-1232//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The fmin and fminf procedures shall return -0 if one argument is -0 and the
   * other +0 .
   */

  float x = -0.0f;
  float y = 0.0f;
  __VERIFIER_precond_reach();
  float res = fmin_float(x, y);

  // x is -0 and y is +0, the result shall be -0
  if (!(res == -0.0f && __signbit_float(res) == 1)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
