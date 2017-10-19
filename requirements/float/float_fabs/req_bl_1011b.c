#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_fabs.h"

int main() {

  /* REQ-BL-1011
   * The fabs and fabsf procedures shall return +0 , if the argument x is -+0.
   */

  float x = -0.0f;
  __VERIFIER_precond_reach();
  float res = fabs_float(x);

  // x is -0, result shall be +0
  if (!(res == -0.0f && __signbit_float(res) == 1)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
