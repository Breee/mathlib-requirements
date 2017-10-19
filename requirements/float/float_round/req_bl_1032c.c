#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_round.h"

int main() {

  /*
   * REQ-BL-1032//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The round and roundf procedures shall return the argument, if the argument
   * x is +-0 or +-Inf .
   */

  float x = 1.0f / 0.0f; // INF
  __VERIFIER_precond_reach();
  float res = round_float(x);

  // result shall be x
  if (!isinf_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
