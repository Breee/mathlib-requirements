#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_fmod.h"

int main() {

  /* REQ-BL-1130:
  * The fmod and fmodf procedures shall return x ,
  * if the argument x is +-0 and the argument y is not zero.
  */

  float x = -0.0f;
  float y = __VERIFIER_nondet_float();

  if ((y < 0.0f || y > 0.0f)) {
    __VERIFIER_precond_reach();

    float res = fmod_float(x, y);

    // x is -0, y is not 0, result shall be -0
    if (!(res == -0.0f && __signbit_float(res) == 1)) {
      __VERIFIER_error();
      return 1;
    }
  }

  return 0;
}
