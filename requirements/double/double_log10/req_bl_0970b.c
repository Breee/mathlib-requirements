#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_log10.h"

int main() {

  /* REQ-BL-0970
   * The log10 and log10f procedures shall return NaN if the argument x is finite and less than 0 or x is -Inf.
   */

  double x = -1.0/0.0; // -INF
  __VERIFIER_precond_reach();
  double res = __ieee754_log10(x);

  // x is -inf, result shall be NAN
  if (!isnan_double(res)) {
    __VERIFIER_error();
    return 1;
  }
  
	return 0;
}
