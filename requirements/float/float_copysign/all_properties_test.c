#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_copysign.h"

int main() {

  /*
   * REQ-BL-1381:
   * The copysign and copysignf procedures shall return NaN if the argument x is
   * NaN .
   */

  float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();
  float res = copysign_float(x, y);
  return res;
}
