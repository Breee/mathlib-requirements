#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_sin.h"

int main() {

  /*
   * REQ-BL-0220//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The sin and sinf procedures shall return the value of the argument if the
   * argument is ±0 .
   */

  float x = 0.0f;
  __VERIFIER_precond_reach();
  float res = sin_float(x);

  // x is +0, result is +0
  if (!(res == 0.0f && __signbit_float(res) == 0)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
