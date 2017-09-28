#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "../float_fmod/float_fmod.h"
#include "float_pow.h"

int main() {

  /*
   * REQ-BL-0864//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return:
   *   +-Inf respectively if y is an odd integer, or
   *   +Inf if y is not an odd integer.
   * If the argument y is < 0 and x is 0.
   */

	float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();

  // x = -0, y even integer
  if(x == -0.0f && y < 0.0f && (fmod_float(y,2.0f) == 0.0f) && isinteger_float(y)){
    __VERIFIER_precond_reach();

    float res = __ieee754_powf(x,y);

    // result shall be +Inf
    if(!isinf_float(res)){
      __VERIFIER_error();
      return 1;
    }
  }

	return 0;
}
