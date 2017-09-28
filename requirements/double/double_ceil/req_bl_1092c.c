#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_ceil.h"

int main() {

  /*
   * REQ-BL-1092:
   * The ceil and ceilf procedures shall return the argument, if the argument x is -+0 or -+Inf.
   */

  double x = INFINITY;

  if (isinf_double(x)) {

    __VERIFIER_precond_reach();

  	double res = ceil_double(x);

    // x is -+0 or +inf , the result shall be x
  	if (res != x)	{
  		__VERIFIER_error();
  		return 1;
  	}

	}

	return 0;
}
