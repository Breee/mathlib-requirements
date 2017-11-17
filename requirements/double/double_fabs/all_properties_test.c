#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_fabs.h"


int main() {

  /* REQ-BL-1010
   * The fabs and fabsf procedures shall return NaN , if the argument x is NaN.
   */

  double x = __VERIFIER_nondet_double();
  double res = fabs_double(x);
	return res;
}
