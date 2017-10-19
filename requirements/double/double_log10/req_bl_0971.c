#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_log10.h"


int main()
{

  /* REQ-BL-0971
   * The log10 and log10f procedures shall return NaN , if the argument x is NaN .
   */

  double x = 0.0/0.0; // NAN
  __VERIFIER_precond_reach();

  double res = __ieee754_log10(x);

  // x is NAN, result shall be NAN
  if (!isnan_double(res)) {
    __VERIFIER_error();
    return 1;
  }

	return 0;
}
