#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "../float_fmod/float_fmod.h"
#include "float_pow.h"

int main() {

  /*
   * REQ-BL-0886//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return +0, if the argument x is +-0 and
   * the argument y is > 0
   * and not an odd integer.
   */

  float x = 0.0f;
  float y = __VERIFIER_nondet_float();

  // x = +0, y > 0, even integer.
  if (y > 0 && (fmod_float(y, 2.0f) == 1.0f) && isinteger_float(y)) {

    __VERIFIER_precond_reach();

    float res = __ieee754_powf(x, y);

    // result shall be +0
    if (!(res == 0.0f && __signbit_float(res) == 0)) {
      __VERIFIER_error();
      return 1;
    }
  }

  return 0;
}
