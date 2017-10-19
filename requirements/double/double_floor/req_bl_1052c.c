#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"

int main() {

  /* REQ-BL-1052
   * The floor and floorf procedures shall return the argument, if the argument x is +-0 or +-Inf.
   */

  double x = -0.0;
  __VERIFIER_precond_reach();
  double res = floor_double(x);

  // x is -0, then the result shall be -0
  if (!(res == -0.0 && __signbit_double(res) == 1)) {
  	__VERIFIER_error();
  	return 1;
  }

	return 0;
}
