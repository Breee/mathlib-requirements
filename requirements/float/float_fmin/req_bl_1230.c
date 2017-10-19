#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_fmin.h"

int main() {

  /*
   * REQ-BL-1230:
   * The fmax and fmaxf procedures shall return NaN,
   * if the arguments x and y are NaN.
   */

  float x = 0.0f / 0.0f; // NAN
  float y = 0.0f / 0.0f; // NAN
  __VERIFIER_precond_reach();
  float res = fmin_float(x, y);

  if (!isnan_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
