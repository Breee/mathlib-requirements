#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_fabs.h"


int main() {

  /* REQ-BL-1010
   * The fabs and fabsf procedures shall return NaN , if the argument x is NaN.
   */

  double x = 0.0/0.0; // NAN
  __VERIFIER_precond_reach();
  double res = fabs_double(x);

  // x is NAN, result shall be NAN
  if (!isnan_double(res)) {
  	__VERIFIER_error();
  	return 1;
  }

	return 0;
}
