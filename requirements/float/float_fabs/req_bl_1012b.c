#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_fabs.h"

int main()
{

  /*
   * REQ-BL-1011
   * The fabs and fabsf procedures shall return +Inf , if the argument x is +-Inf .
   */

  float x = -INFINITY;

  if (isinf_float(x)) {
    __VERIFIER_precond_reach();

    float res = fabs_float(x);

    // x is -inf, result shall be +inf
    if (!isinf_float(res)) {
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
