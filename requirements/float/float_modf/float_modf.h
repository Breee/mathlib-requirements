static const float one_modf= 1.0;

float modf_float(float x, float *iptr) {
 __int32_t i0,j0;
 __uint32_t i;
 do { ieee_float_shape_type gf_u; gf_u.value = (x); (i0) = gf_u.word; } while (0);
 j0 = ((i0>>23)&0xff)-0x7f;
 if(j0<23) {
     if(j0<0) {
         do { ieee_float_shape_type sf_u; sf_u.word = (i0&0x80000000); (*iptr) = sf_u.value; } while (0);
  return x;
     } else {
  i = (0x007fffff)>>j0;
  if((i0&i)==0) {
      __uint32_t ix;
      *iptr = x;
      do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
      do { ieee_float_shape_type sf_u; sf_u.word = (ix&0x80000000); (x) = sf_u.value; } while (0);
      return x;
  } else {
      do { ieee_float_shape_type sf_u; sf_u.word = (i0&(~i)); (*iptr) = sf_u.value; } while (0);
      return x - *iptr;
  }
     }
 } else {
     __uint32_t ix;
     *iptr = x*one_modf;
     do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
     do { ieee_float_shape_type sf_u; sf_u.word = (ix&0x80000000); (x) = sf_u.value; } while (0);
     return x;
 }
}