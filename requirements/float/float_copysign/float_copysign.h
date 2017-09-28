float copysign_float(float x, float y) {
__uint32_t ix,iy;
do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
do { ieee_float_shape_type gf_u; gf_u.value = (y); (iy) = gf_u.word; } while (0);
do { ieee_float_shape_type sf_u; sf_u.word = ((ix&0x7fffffff)|(iy&0x80000000)); (x) = sf_u.value; } while (0);
       return x;
}
