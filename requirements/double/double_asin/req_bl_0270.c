#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_asin.h"

int main() {

  /*
   * REQ-BL-0270
   * The asin and asinf procedures shall return the value of the argument if the argument is +-0 .
   */

  double x = __VERIFIER_nondet_double();

  // x is not +-0 we don't want to continue
  if (x == -0.0f || x == +0.0f) {
    __VERIFIER_precond_reach();

  	double res = __ieee754_asin(x);

    // x is +-0, the result shall be x
  	if (res != x) {
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
