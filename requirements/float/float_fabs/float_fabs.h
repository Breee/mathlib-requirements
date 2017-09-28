float fabs_float(float x) {
__uint32_t ix;
do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
do { ieee_float_shape_type sf_u; sf_u.word = (ix&0x7fffffff); (x) = sf_u.value; } while (0);
       return x;
}
