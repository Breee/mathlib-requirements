#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_pow.h"

int main() {

  /*
  * REQ-BL-0860//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
  * The pow and powf procedures shall return NaN if the argument x is < 0 and finite,
  * and the argument y is a finite, non-integer value.
  */

	float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();

  if(x < 0 && isfinite_float(x) && isfinite_float(y) && !isinteger_float(y)){
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
