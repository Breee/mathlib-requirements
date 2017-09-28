double fabs_double(double x) {
__uint32_t high;
do { ieee_double_shape_type gh_u; gh_u.value = (x); (high) = gh_u.parts.msw; } while (0);
do { ieee_double_shape_type sh_u; sh_u.value = (x); sh_u.parts.msw = (high&0x7fffffff); (x) = sh_u.value; } while (0);
       return x;
}
