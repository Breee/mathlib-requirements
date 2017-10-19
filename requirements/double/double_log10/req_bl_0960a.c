#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_log10.h"

int main() {

  /* REQ-BL-0960
   * The log10 and log10f procedures shall return -Inf if the argument x is +-0.
   */

  double x = 0.0;
  __VERIFIER_precond_reach();
  double res = __ieee754_log10(x);

  // x is +0, the result shall be -inf
  if (!isinf_double(res)) {
  	__VERIFIER_error();
  	return 1;
  }

	return 0;
}
