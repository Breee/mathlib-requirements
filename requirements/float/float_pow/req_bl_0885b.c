#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "../float_fmod/float_fmod.h"
#include "float_pow.h"

int main() {

  /*
   * REQ-BL-0885//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return +-0 respectively,
   * if the argument x is +-0 and the argument y is an odd integer > 0.
   */

	float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();

  // x = -0, y > 0, odd integer.
  if(x == -0.0f && y > 0 && (fmod_float(y,2.0f) == 1.0f) && isinteger_float(y)){

    __VERIFIER_precond_reach();

    float res = __ieee754_powf(x,y);

    // result shall be -0
    if(res != -0.0f){
      __VERIFIER_error();
      return 1;
    }
  }

	return 0;
}
