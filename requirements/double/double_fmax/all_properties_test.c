#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_fmax.h"

int main()
{
  double x = __VERIFIER_nondet_double();
	double y = __VERIFIER_nondet_double();
  double res = fmax_double(x, y);
	return res;
}
