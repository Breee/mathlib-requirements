#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_modf.h"

int main() {
  double x = __VERIFIER_nondet_double();
  double iptr;
  double res = modf_double(x, &iptr);
	return res;
}
