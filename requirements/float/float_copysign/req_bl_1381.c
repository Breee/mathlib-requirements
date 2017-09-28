#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_copysign.h"

int main() {

  /*
   * REQ-BL-1381:
   * The copysign and copysignf procedures shall return NaN if the argument x is NaN .
   */

  float x = NAN;
  float y = __VERIFIER_nondet_float();

  if (isnan_float(x)) {
    __VERIFIER_precond_reach();

  	float res = copysign_float(x, y);

    // x is nan, y can be any, the result shall be NAN
  	if (!isnan_float(res)){
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
