#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_fmax.h"


int main()
{

  /* REQ-BL-1252:
  * The fmax and fmaxf procedures shall return +0 if one argument is -0
  * and the other +0.
  */

  double x = -0.0;
  double y = 0.0;
  __VERIFIER_precond_reach();
  double res = fmax_double(x, y);

  // x is -0 and y is +0, the result shall be +0
  if (!(res == 0.0 && __signbit_double(res) == 0))	{
  	__VERIFIER_error();
  	return 1;
  }

	return 0;
}
