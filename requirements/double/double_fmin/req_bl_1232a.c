#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_fmin.h"

int main() {

  /*
   * REQ-BL-1232//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The fmin and fminf procedures shall return -0 if one argument is -0
   * and the other +0.
   */

  double x = 0.0;
  double y = -0.0;
  __VERIFIER_precond_reach();

  double res = fmin_double(x, y);

  // y is -0 and x is +0, the result shall be -0
  if (!(res == -0.0 && __signbit_double(res) == 1))	{
    __VERIFIER_error();
    return 1;
  }

	return 0;
}
