#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_modf.h"

int main() {

  /* REQ-BL-1210
   * The modf and modff procedures shall return NaN and set the argument ∗iptr to NaN, if the argument x is NaN .
   */

  double x = 0.0/0.0; // NAN
  double iptr;
  __VERIFIER_precond_reach();
  double res = modf_double(x, &iptr);

  // x is NAN, *iptr is NAN result shall be that *iptr and x is NAN
  if (isnan_double(iptr) && !isnan_double(res)) {
  	__VERIFIER_error();
  	return 1;
  }
	return 0;
}
