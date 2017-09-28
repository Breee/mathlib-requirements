#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_acos.h"

int main() {
  /*
   * REQ-BL-0480:
   * The acos and acosf procedures shall return +0 , if the argument x is +1
   */

  double x = __VERIFIER_nondet_double();

  if (x == 1.0) {

    __VERIFIER_precond_reach();

  	double res = __ieee754_acos(x);

    // x is +1, the result shall be +0
  	if (res != 0.0)	{
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
