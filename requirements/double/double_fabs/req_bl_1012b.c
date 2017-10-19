#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_fabs.h"


int main()
{

  /*
   * REQ-BL-1011
   * The fabs and fabsf procedures shall return +Inf , if the argument x is +-Inf .
   */

  double x = -1.0/0.0; // -INF
  __VERIFIER_precond_reach();
  double res = fabs_double(x);

  // x is -inf, result shall be +inf
  if (!isinf_double(res)) {
    __VERIFIER_error();
    return 1;
  }

	return 0;
}
