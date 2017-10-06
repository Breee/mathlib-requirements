double fmin_double(double x, double y) {
 if (__fpclassify_double(x) == 0)
   return y;
 if (__fpclassify_double(y) == 0)
   return x;

 return x < y ? x : y;
}
