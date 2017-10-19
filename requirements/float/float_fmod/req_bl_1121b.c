#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_fmod.h"

int main() {

  /* REQ-BL-1121:
  * The fmod and fmodf procedures shall return NaN, if the argument y is 0.
  */

  float x = __VERIFIER_nondet_float();
  float y = -0.0f;
  __VERIFIER_precond_reach();
  float res = fmod_float(x, y);

  // x is any value, y is -0, the result shall be NAN
  if (!isnan_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
