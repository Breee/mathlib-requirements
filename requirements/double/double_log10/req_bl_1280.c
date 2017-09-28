#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_log10.h"

int main()
{

  /*
   * REQ-BL-1280
   * The log10 and log10f procedures shall return +0, if the argument x is 1.
   */

  double x = 1.0;

  if (x == 1.0) {

    __VERIFIER_precond_reach();

    double res = __ieee754_log10(x);

    // x is  1, result shall be +0
    if (x == 1.0 && res != 0.0) {
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
