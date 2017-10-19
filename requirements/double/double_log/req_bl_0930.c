#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_log.h"

int main()
{

  /* REQ-BL-0930
   * The log and logf procedures shall return +0, if the argument x is 1.
   */

  double x = 1.0;
  __VERIFIER_precond_reach();

  double res = __ieee754_log(x);

  // x is  1, result shall be +0
  if (!(res == 0.0 && __signbit_double(res) == 0)) {
    __VERIFIER_error();
    return 1;
  }

	return 0;
}
