#include "../includes/verify.h"
#include "../includes/math_functions_float.h"
#include "float_pow.h"

int main() {

  /*
   * REQ-BL-0878//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return -0 , if the argument x is -Inf and the argument y is an odd integer < 0.
   */

	float x = -INFINITY;
  float y = __VERIFIER_nondet_float();

  if(isinf_float(x) && y < 0 && isinteger_float(y) && (fmod_float(y,2.0f) == 1.0f)){

    __VERIFIER_precond_reach();

    float res = __ieee754_powf(x, y);

    // result shall be -0
    if(res != -0.0f){
      __VERIFIER_error();
      return 1;
    }
  }

	return 0;
}
