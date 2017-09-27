#include "../includes/verify.h"
#include "../includes/math_functions_float.h"


int main() {

  /*
   * REQ-BL-0730:
   * The sqrt and sqrtf procedures shall return the argument if the argument x is +-0 or +Inf.
   */

  float x = INFINITY;
  // if x is not +-0 or +inf, we dont want to continue
  if (isinf_float(x)) {
    __VERIFIER_precond_reach();

    float res = __ieee754_sqrtf(x);

    // x +inf the result shall be x
    if (res != x)	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
