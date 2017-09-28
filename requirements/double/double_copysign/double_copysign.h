double copysign_double(double x, double y) {
__uint32_t hx,hy;
do { ieee_double_shape_type gh_u; gh_u.value = (x); (hx) = gh_u.parts.msw; } while (0);
do { ieee_double_shape_type gh_u; gh_u.value = (y); (hy) = gh_u.parts.msw; } while (0);
do { ieee_double_shape_type sh_u; sh_u.value = (x); sh_u.parts.msw = ((hx&0x7fffffff)|(hy&0x80000000)); (x) = sh_u.value; } while (0);
       return x;
}
