#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_sqrt.h"

int main() {

  /*
   * REQ-BL-0730:
   * The sqrt and sqrtf procedures shall return the argument if the argument x is +-0 or +Inf.
   */

  float x = __VERIFIER_nondet_float();
  // if x is not +-0 or +inf, we dont want to continue
  if (x == +0.0f || x == -0.0f) {
    __VERIFIER_precond_reach();

    float res = __ieee754_sqrtf(x);

    // x +-0, the result shall be x
    if (res != x)	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
