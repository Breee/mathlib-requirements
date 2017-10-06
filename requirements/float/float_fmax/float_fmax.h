float fmax_float(float x, float y) {
  if (__fpclassify_float(x) == 0) {
    return y;
  }

  if (__fpclassify_float(y) == 0) {
    return x;
  }
  return x > y ? x : y;
}
