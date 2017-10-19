#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_asin.h"

int main() {

  /*
   * REQ-BL-0270
   * The asin and asinf procedures shall return the value of the argument if the argument is +-0 .
   */

  float x = 0.0f;
  __VERIFIER_precond_reach();
  float res = __ieee754_asinf(x);

    // x is +-0, the result shall be x
  	if (!(res == 0.0f && __signbit_float(res) == 0)) {
  		__VERIFIER_error();
  		return 1;
  	}

	return 0;
}
