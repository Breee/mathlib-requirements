#include "../includes/verify.h"
#include "../includes/math_functions_float.h"
#include "float_pow.h"

int main() {

  /*
   * REQ-BL-0870//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return NaN if
   *   the argument y is NaN and x is not 1, or
   *   the argument x is NaN and y is not +-0 .
   */

	float x = __VERIFIER_nondet_float();
  float y = NAN;

  if(x != 1.0f && isnan_float(y)){
    __VERIFIER_precond_reach();

    float res = __ieee754_powf(x,y);

    // result shall be NAN
    if(!isnan_float(res)){
      __VERIFIER_error();
      return 1;
    }
  }

	return 0;
}
