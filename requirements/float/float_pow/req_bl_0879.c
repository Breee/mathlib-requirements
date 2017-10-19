#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "../float_fmod/float_fmod.h"
#include "float_pow.h"

int main() {

  /*
   * REQ-BL-0879//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return +0, if the argument x is -Inf and
   * the argument y is an even integer < 0.
   */

  float x = -1.0f / 0.0f; // -INF
  float y = __VERIFIER_nondet_float();

  if (y < 0 && isinteger_float(y) && (fmod_float(y, 2.0f) == 0.0f)) {

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
