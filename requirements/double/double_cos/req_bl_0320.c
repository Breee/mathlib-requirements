#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_cos.h"


int main() {

  /*
   * REQ-BL-0320//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The cos and cosf procedures shall return 1.0 if the argument is +-0.
   */

  double x = __VERIFIER_nondet_double();

  if (x == 0.0 || x == -0.0) {
    __VERIFIER_precond_reach();

  	double res = cos_double(x);

    // x is +-0, the result shall be 1.0
  	if (res != 1.0)	{
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
