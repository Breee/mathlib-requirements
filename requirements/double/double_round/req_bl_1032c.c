#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_round.h"

int main() {

  /*
   * REQ-BL-1032//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The round and roundf procedures shall return the argument, if the argument x is +-0 or +-Inf .
   */

	double x = 1.0/0.0; // INF
  __VERIFIER_precond_reach();
  double res = round_double(x);

  // result shall be +inf
  if(!isinf_double(x)){
    __VERIFIER_error();
    return 1;
  }

	return 0;
}
