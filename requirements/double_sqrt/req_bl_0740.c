#include "../includes/verify.h"
#include "../includes/math_functions_double.h"

int main() {

  /*
   * REQ-BL-0740:
   * The sqrt and sqrtf procedures shall return NaN, if the argument x is -Inf.
   */

   double x = -INFINITY;

  if (isinf_double(x)) {
    __VERIFIER_precond_reach();

    double res = __ieee754_sqrt(x);

    // x -inf, the result shall be NAN
    if (!isnan_double(res))	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
