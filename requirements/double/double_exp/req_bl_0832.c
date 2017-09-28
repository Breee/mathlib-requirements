#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_exp.h"


int main() {


  /* REQ-BL-0832
   * The exp and expf procedures shall return 1 if the argument x is +-0.
   */

  double x = __VERIFIER_nondet_double();

  if (x == 0.0 || x == -0.0) {

    __VERIFIER_precond_reach();

  	double res = __ieee754_exp(x);

    // x is +-0, result shall be 1.
  	if (res != 1.0) {
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
