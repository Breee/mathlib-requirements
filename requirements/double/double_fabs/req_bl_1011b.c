#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_fabs.h"

int main()
{

  /* REQ-BL-1011
   * The fabs and fabsf procedures shall return +0 , if the argument x is -+0.
   */

  double x = -0.0;
  __VERIFIER_precond_reach();

    double res = fabs_double(x);

    // x is +-0, result shall be +0
    if (!(res == 0.0 && __signbit_double(res) == 0)) {
      __VERIFIER_error();
      return 1;
    }

	return 0;
}
