#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_sqrt.h"

int main() {

  /*
   * REQ-BL-0740:
   * The sqrt and sqrtf procedures shall return NaN, if the argument x is -Inf.
   */

   float x = -INFINITY;
  // if x is not -inf, we dont want to continue
  if (isinf_float(x)) {
    __VERIFIER_precond_reach();

    float res = __ieee754_sqrtf(x);

    // x -inf, the result shall be NAN
    if (!isnan_float(res))	{
      __VERIFIER_error();
      return 1;
    }

	}
	return 0;
}
