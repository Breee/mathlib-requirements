#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_ceil.h"

int main() {

  /*
   * REQ-BL-1092:
   * The ceil and ceilf procedures shall return the argument, if the argument x is -+0 or -+Inf.
   */

  float x = 0.0f;

  if (x == 0.0f) {

    __VERIFIER_precond_reach();

  	float res = ceil_float(x);

    // x is -+0 or +inf , the result shall be x
  	if (res != x)	{
  		__VERIFIER_error();
  		return 1;
  	}

	}

	return 0;
}
