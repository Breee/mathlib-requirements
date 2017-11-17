#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_hypot.h"

int main() {
  float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();
  float res = __ieee754_hypotf(x, y);
  return res;
}
