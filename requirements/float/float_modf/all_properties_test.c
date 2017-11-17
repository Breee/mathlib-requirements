#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_modf.h"

int main() {
  float x = __VERIFIER_nondet_float();
  float iptr;
  float res = modf_float(x, &iptr);
  return res;
}
