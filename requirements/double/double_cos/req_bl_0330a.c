#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_cos.h"

int main() {

  /*
   * REQ-BL-0330//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The cos and cosf procedures shall return NaN , if the argument is +-Inf .
   */

  double x = 1.0/0.0; // INF
  __VERIFIER_precond_reach();
  double res = cos_double(x);

  // x is +INF, the result shall be NAN
  if (!isnan_double(res))	{
  	__VERIFIER_error();
  	return 1;
  }

	return 0;
}
