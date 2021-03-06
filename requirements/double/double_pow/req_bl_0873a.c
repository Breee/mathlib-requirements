#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_pow.h"

int main() {

  /*
   * REQ-BL-0873//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * shall return 1.0 if  x == -1 and y == +-inf.
   */

	double x = -1.0;
  double y = 1.0/0.0; // INF
  __VERIFIER_precond_reach();

  double res = __ieee754_pow(x, y);

  // result shall be 1.0
  if(res != 1.0){
    __VERIFIER_error();
    return 1;
  }

	return 0;
}
