#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_fmod.h"

int main() {

  /* REQ-BL-1121:
  * The fmod and fmodf procedures shall return NaN, if the argument y is 0.
  */

  float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();
  float res = fmod_float(x, y);
  return res;
}
