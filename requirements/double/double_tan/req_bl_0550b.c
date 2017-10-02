#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_tan.h"


int main() {

  /*
   * REQ-BL-0550//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The tan and tanf procedures shall return NaN , if the argument is ±Inf ..
   */

  double x = -INFINITY;

  if (isinf_double(x)) {
    __VERIFIER_precond_reach();

  	double res = tan_double(x);

    // x is -INF, the result shall be NAN
  	if (!isnan_double(res))	{
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}