#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_fmod.h"

int main() {

  /* REQ-BL-1131:
   * The fmod and fmodf procedures shall return the argument x,
   * if the argument x is not ±Inf and the argument y is ±Inf
   */

  float x = __VERIFIER_nondet_float();
  float y = -1.0f / 0.0f; // -INF

  if (isfinite_float(x)) {

    __VERIFIER_precond_reach();

    float res = fmod_float(x, y);

    // x is not +-inf, y is -inf, result shall be x
    if (res != x) {
      __VERIFIER_error();
      return 1;
    }
  }

  return 0;
}
