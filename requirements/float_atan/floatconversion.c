//#Safe
//
// This program tests whether two representations of pi/2 are equal.
// Using GCC to verify this program yields a "correct" result.
// In the current implementation of Ultimate, Ultimate reports the program to
// be incorrect which may be a bug.
//
// Author: Marius Greitschus (greitsch@informatik.uni-freiburg.de)
// Date  : 20170919
//
#include <math.h>
#include "../includes/verify.h"

int main() {
  double pi = 3.14159265358979323846;
  float res = 1.570796326797894159; // PI/2
 
  if (res != (float)pi/2.0f)
  {
	  __VERIFIER_error();
  }
}
