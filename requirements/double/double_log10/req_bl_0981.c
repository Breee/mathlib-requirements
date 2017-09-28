#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_log10.h"

int main()
{

  /*
   * REQ-BL-0981
   * The log10 and log10f procedures shall return +Inf, if the argument x is +Inf .
   */

  double x = INFINITY;

  if (isinf_double(x)) {
    __VERIFIER_precond_reach();

    double res = __ieee754_log10(x);

    // x is +inf, result shall be +inf
    if (!isinf_double(res)) {
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
