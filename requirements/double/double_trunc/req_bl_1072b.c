#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_trunc.h"

int main()
{

  /* REQ-BL-1072
   * The trunc and truncf procedures shall return the argument, if the argument x is +-0 or +-Inf .
   */

  double x = 0.0;
  __VERIFIER_precond_reach();
  double res = trunc_double(x);

  // x is +-0, result shall be x.
  if (!(res == 0.0 && __signbit_double(res) == 0)) {
  	__VERIFIER_error();
  	return 1;
  }

	return 0;
}
