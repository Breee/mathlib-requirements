#include "../includes/verify.h"
#include "../includes/math_functions_double.h"

double fmin_double(double x, double y) {
 if (__fpclassifyd(x) == 0)
   return y;
 if (__fpclassifyd(y) == 0)
   return x;

 return x < y ? x : y;
}


int main()
{

  /*
   * REQ-BL-1230:
   * The fmin and fminf procedures shall return NaN,
   * if the arguments x and y are NaN.
   */

  double x = NAN;
  double y = NAN;

	if (isnan_double(x) && isnan_double(y)) {
    __VERIFIER_precond_reach();

    double res = fmin_double(x, y);

    if (!isnan_double(res))	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
