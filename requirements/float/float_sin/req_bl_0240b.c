#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_sin.h"

int main() {

  /*
   * REQ-BL-0240//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The sin and sinf procedures shall return NaN if x is ±Inf
   */

  float x = -1.0f / 0.0f; // -INF
  __VERIFIER_precond_reach();
  float res = sin_float(x);

  // x is -INF, the result shall be NAN
  if (!isnan_float(res)) {
    __VERIFIER_error();
    return 1;
  }
  return 0;
}
