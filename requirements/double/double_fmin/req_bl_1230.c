#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_fmin.h"

int main()
{

  /*
   * REQ-BL-1230:
   * The fmin and fminf procedures shall return NaN,
   * if the arguments x and y are NaN.
   */

  double x = 0.0/0.0; // NAN
  double y = 0.0/0.0; // NAN
  __VERIFIER_precond_reach();
  double res = fmin_double(x, y);

  if (!isnan_double(res))	{
    __VERIFIER_error();
    return 1;
  }

	return 0;
}
