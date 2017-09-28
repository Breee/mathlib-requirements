float fmin_float(float x, float y) {
 if (__fpclassifyf(x) == 0)
   return y;
 if (__fpclassifyf(y) == 0)
   return x;

 return x < y ? x : y;
}
