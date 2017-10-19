#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_fmax.h"

int main() {

  /* REQ-BL-1252:
  * The fmax and fmaxf procedures shall return +0 if one argument is -0
  * and the other +0.
  */

  float x = 0.0f;
  float y = -0.0f;
  __VERIFIER_precond_reach();
  float res = fmax_float(x, y);

  // y is -0 and x is +0, the result shall be +0
  if (!(res == 0.0f && __signbit_float(res) == 0)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
