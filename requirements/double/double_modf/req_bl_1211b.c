#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_modf.h"

int main() {

  /* REQ-BL-1211
   * The modf and modff procedures shall return ±0 and set the argument ∗iptr to +-Inf , if the argument x is +-Inf .
   */

  double x = -1.0/0.0; // INF
  double iptr = __VERIFIER_nondet_double();
  __VERIFIER_precond_reach();
  double res = modf_double(x, &iptr);

  // x is inf, *iptr is inf, result shall be -0
  if (isinf_double(iptr) && !(res == -0.0 && __signbit_double(res) == 1)) {
  	__VERIFIER_error();
  	return 1;
  }

	return 0;
}
