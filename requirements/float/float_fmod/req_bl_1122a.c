#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_fmod.h"

int main() {

  /* REQ-BL-1121:
  * The fmod and fmodf procedures shall return NaN , if the argument x is +-Inf.
  */

  float x = 1.0f / 0.0f; // INF
  float y = __VERIFIER_nondet_float();
  __VERIFIER_precond_reach();
  float res = fmod_float(x, y);

  // y is any value, x is +inf, the result shall be NAN
  if (!isnan_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
