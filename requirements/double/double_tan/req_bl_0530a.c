#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_tan.h"

int main() {

  /*
   * REQ-BL-0530//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The tan and tanf procedures shall return the value of the argument if the argument is ±0 ..
   */

  double x = 0.0;
  __VERIFIER_precond_reach();
  double res = tan_double(x);

  // x is +0, the result shall be +0.
  if (!(res == 0.0 && __signbit_double(res) == 0))	{
  	__VERIFIER_error();
  	return 1;
  }

	return 0;
}
