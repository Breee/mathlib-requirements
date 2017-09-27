#include "../includes/verify.h"
#include "../includes/math_functions_double.h"


int main() {

  /*
   * REQ-BL-0730:
   * The sqrt and sqrtf procedures shall return the argument if the argument x is +-0 or +Inf.
   */

  double x = __VERIFIER_nondet_double();

  if (x == 0.0 || x == -0.0) {
    __VERIFIER_precond_reach();

    double res = __ieee754_sqrt(x);

    // x  +-0, the result shall be x
    if (res != x)	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
