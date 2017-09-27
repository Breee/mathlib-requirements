/*
* preprocessed newlib functions
*/

// infinity check for doubles
int isinf_double(double x) {
 __int32_t hx,lx;
 do { ieee_double_shape_type ew_u; ew_u.value = (x); (hx) = ew_u.parts.msw; (lx) = ew_u.parts.lsw; } while (0);
 hx &= 0x7fffffff;
 hx |= (__uint32_t)(lx|(-lx))>>31;
 hx = 0x7ff00000 - hx;
 return 1 - (int)((__uint32_t)(hx|(-hx))>>31);
}

// nan check for doubles
int isnan_double(double x) {
  #if defined(ULTIMATE)
    return x != x;
  #else
    __int32_t hx,lx;
    do { ieee_double_shape_type ew_u; ew_u.value = (x); (hx) = ew_u.parts.msw; (lx) = ew_u.parts.lsw; } while (0);
    hx &= 0x7fffffff;
    hx |= (__uint32_t)(lx|(-lx))>>31;
    hx = 0x7ff00000 - hx;
    return (int)(((__uint32_t)(hx))>>31);
  #endif
}

int isfinite_double(double x){
__int32_t hx;
do { ieee_double_shape_type gh_u; gh_u.value = (x); (hx) = gh_u.parts.msw; } while (0);
return (int)((__uint32_t)((hx&0x7fffffff)-0x7ff00000)>>31);
}

/*
 * __fpclassify Categorizes floating point value arg into the following categories:
 * zero, subnormal, normal, infinite, NAN, or implementation-defined category.
 * Returns One of FP_INFINITE, FP_NAN, FP_NORMAL, FP_SUBNORMAL, FP_ZERO or implementation-defined type, specifying the category of arg.
 */

int __fpclassifyd (double x) {
  __uint32_t msw, lsw;

  do { ieee_double_shape_type ew_u; ew_u.value = (x); (msw) = ew_u.parts.msw; (lsw) = ew_u.parts.lsw; } while (0);

  if ((msw == 0x00000000 && lsw == 0x00000000) ||
      (msw == 0x80000000 && lsw == 0x00000000))
    return 2;
  else if ((msw >= 0x00100000 && msw <= 0x7fefffff) ||
           (msw >= 0x80100000 && msw <= 0xffefffff))
    return 4;
  else if ((msw >= 0x00000000 && msw <= 0x000fffff) ||
           (msw >= 0x80000000 && msw <= 0x800fffff))

    return 3;
  else if ((msw == 0x7ff00000 && lsw == 0x00000000) ||
           (msw == 0xfff00000 && lsw == 0x00000000))
    return 1;
  else
    return 0;
}

static const double two54 = 1.80143985094819840000e+16,
twom54 = 5.55111512312578270212e-17,
huge = 1.0e+300,
tiny = 1.0e-300;
static const double one = 1.0;
static const double Zero[] = {0.0, -0.0,};

static const double bp[] = {1.0, 1.5,},
dp_h[] = { 0.0, 5.84962487220764160156e-01,},
dp_l[] = { 0.0, 1.35003920212974897128e-08,},
zero = 0.0,
two = 2.0,
two53 = 9007199254740992.0,
L1 = 5.99999999999994648725e-01,
L2 = 4.28571428578550184252e-01,
L3 = 3.33333329818377432918e-01,
L4 = 2.72728123808534006489e-01,
L5 = 2.30660745775561754067e-01,
L6 = 2.06975017800338417784e-01,
P1 = 1.66666666666666019037e-01,
P2 = -2.77777777770155933842e-03,
P3 = 6.61375632143793436117e-05,
P4 = -1.65339022054652515390e-06,
P5 = 4.13813679705723846039e-08,
lg2 = 6.93147180559945286227e-01,
lg2_h = 6.93147182464599609375e-01,
lg2_l = -1.90465429995776804525e-09,
ovt = 8.0085662595372944372e-0017,
cp = 9.61796693925975554329e-01,
cp_h = 9.61796700954437255859e-01,
cp_l = -7.02846165095275826516e-09,
ivln2 = 1.44269504088896338700e+00,
ivln2_h = 1.44269502162933349609e+00,
ivln2_l = 1.92596299112661746887e-08;


double copysign_double(double x, double y){
__uint32_t hx,hy;
do { ieee_double_shape_type gh_u; gh_u.value = (x); (hx) = gh_u.parts.msw; } while (0);
do { ieee_double_shape_type gh_u; gh_u.value = (y); (hy) = gh_u.parts.msw; } while (0);
do { ieee_double_shape_type sh_u; sh_u.value = (x); sh_u.parts.msw = ((hx&0x7fffffff)|(hy&0x80000000)); (x) = sh_u.value; } while (0);
       return x;
}

double scalbn_double(double x, int n) {
 __int32_t k,hx,lx;
 do { ieee_double_shape_type ew_u; ew_u.value = (x); (hx) = ew_u.parts.msw; (lx) = ew_u.parts.lsw; } while (0);
        k = (hx&0x7ff00000)>>20;
        if (k==0) {
            if ((lx|(hx&0x7fffffff))==0) return x;
     x *= two54;
     do { ieee_double_shape_type gh_u; gh_u.value = (x); (hx) = gh_u.parts.msw; } while (0);
     k = ((hx&0x7ff00000)>>20) - 54;
            if (n< -50000) return tiny*x;
     }
        if (k==0x7ff) return x+x;
        k = k+n;
        if (k > 0x7fe) return huge*copysign_double(huge,x);
        if (k > 0)
     {do { ieee_double_shape_type sh_u; sh_u.value = (x); sh_u.parts.msw = ((hx&0x800fffff)|(k<<20)); (x) = sh_u.value; } while (0); return x;}
        if (k <= -54) {
            if (n > 50000)
  return huge*copysign_double(huge,x);
     else return tiny*copysign_double(tiny,x);
      }
        k += 54;
 do { ieee_double_shape_type sh_u; sh_u.value = (x); sh_u.parts.msw = ((hx&0x800fffff)|(k<<20)); (x) = sh_u.value; } while (0);
        return x*twom54;
}


double __ieee754_sqrt(double x) {
 double z;
 __int32_t sign = 0x80000000;
 __uint32_t r,t1,s1,ix1,q1;
 __int32_t ix0,s0,q,m,t,i;
 do { ieee_double_shape_type ew_u; ew_u.value = (x); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0);

 if((ix0&0x7ff00000)==0x7ff00000) {
     return x*x+x;
 }

 if(ix0<=0) {
     if(((ix0&(~sign))|ix1)==0) return x;
     else if(ix0<0)
  return (x-x)/(x-x);
 }

 m = (ix0>>20);
 if(m==0) {
     while(ix0==0) {
  m -= 21;
  ix0 |= (ix1>>11); ix1 <<= 21;
     }
     for(i=0;(ix0&0x00100000)==0;i++) ix0<<=1;
     m -= i-1;
     ix0 |= (ix1>>(32-i));
     ix1 <<= i;
 }
 m -= 1023;
 ix0 = (ix0&0x000fffff)|0x00100000;
 if(m&1){
     ix0 += ix0 + ((ix1&sign)>>31);
     ix1 += ix1;
 }
 m >>= 1;
 ix0 += ix0 + ((ix1&sign)>>31);
 ix1 += ix1;
 q = q1 = s0 = s1 = 0;
 r = 0x00200000;

 while(r!=0) {
     t = s0+r;
     if(t<=ix0) {
  s0 = t+r;
  ix0 -= t;
  q += r;
     }
     ix0 += ix0 + ((ix1&sign)>>31);
     ix1 += ix1;
     r>>=1;
 }
 r = sign;
 while(r!=0) {
     t1 = s1+r;
     t = s0;
     if((t<ix0)||((t==ix0)&&(t1<=ix1))) {
  s1 = t1+r;
  if(((t1&sign)==sign)&&(s1&sign)==0) s0 += 1;
  ix0 -= t;
  if (ix1 < t1) ix0 -= 1;
  ix1 -= t1;
  q1 += r;
     }
     ix0 += ix0 + ((ix1&sign)>>31);
     ix1 += ix1;
     r>>=1;
 }

 if((ix0|ix1)!=0) {
     z = one-tiny;
     if (z>=one) {
         z = one+tiny;
         if (q1==(__uint32_t)0xffffffff) { q1=0; q += 1;}
  else if (z>one) {
      if (q1==(__uint32_t)0xfffffffe) q+=1;
      q1+=2;
  } else
             q1 += (q1&1);
     }
 }
 ix0 = (q>>1)+0x3fe00000;
 ix1 = q1>>1;
 if ((q&1)==1) ix1 |= sign;
 ix0 += (m <<20);
 do { ieee_double_shape_type iw_u; iw_u.parts.msw = (ix0); iw_u.parts.lsw = (ix1); (z) = iw_u.value; } while (0);
 return z;
}



double fmod_double(double x, double y){
 __int32_t n,hx,hy,hz,ix,iy,sx,i;
 __uint32_t lx,ly,lz;

 do { ieee_double_shape_type ew_u; ew_u.value = (x); (hx) = ew_u.parts.msw; (lx) = ew_u.parts.lsw; } while (0);
 do { ieee_double_shape_type ew_u; ew_u.value = (y); (hy) = ew_u.parts.msw; (ly) = ew_u.parts.lsw; } while (0);
 sx = hx&0x80000000;
 hx ^=sx;
 hy &= 0x7fffffff;


 if((hy|ly)==0||(hx>=0x7ff00000)||
   ((hy|((ly|-ly)>>31))>0x7ff00000))
     return (x*y)/(x*y);
 if(hx<=hy) {
     if((hx<hy)||(lx<ly)) return x;
     if(lx==ly)
  return Zero[(__uint32_t)sx>>31];
 }


 if(hx<0x00100000) {
     if(hx==0) {
  for (ix = -1043, i=lx; i>0; i<<=1) ix -=1;
     } else {
  for (ix = -1022,i=(hx<<11); i>0; i<<=1) ix -=1;
     }
 } else ix = (hx>>20)-1023;


 if(hy<0x00100000) {
     if(hy==0) {
  for (iy = -1043, i=ly; i>0; i<<=1) iy -=1;
     } else {
  for (iy = -1022,i=(hy<<11); i>0; i<<=1) iy -=1;
     }
 } else iy = (hy>>20)-1023;


 if(ix >= -1022)
     hx = 0x00100000|(0x000fffff&hx);
 else {
     n = -1022-ix;
     if(n<=31) {
         hx = (hx<<n)|(lx>>(32-n));
         lx <<= n;
     } else {
  hx = lx<<(n-32);
  lx = 0;
     }
 }
 if(iy >= -1022)
     hy = 0x00100000|(0x000fffff&hy);
 else {
     n = -1022-iy;
     if(n<=31) {
         hy = (hy<<n)|(ly>>(32-n));
         ly <<= n;
     } else {
  hy = ly<<(n-32);
  ly = 0;
     }
 }


 n = ix - iy;
 while(n--) {
     hz=hx-hy;lz=lx-ly; if(lx<ly) hz -= 1;
     if(hz<0){hx = hx+hx+(lx>>31); lx = lx+lx;}
     else {
      if((hz|lz)==0)
      return Zero[(__uint32_t)sx>>31];
      hx = hz+hz+(lz>>31); lx = lz+lz;
     }
 }
 hz=hx-hy;lz=lx-ly; if(lx<ly) hz -= 1;
 if(hz>=0) {hx=hz;lx=lz;}


 if((hx|lx)==0)
     return Zero[(__uint32_t)sx>>31];
 while(hx<0x00100000) {
     hx = hx+hx+(lx>>31); lx = lx+lx;
     iy -= 1;
 }
 if(iy>= -1022) {
     hx = ((hx-0x00100000)|((iy+1023)<<20));
     do { ieee_double_shape_type iw_u; iw_u.parts.msw = (hx|sx); iw_u.parts.lsw = (lx); (x) = iw_u.value; } while (0);
 } else {
     n = -1022 - iy;
     if(n<=20) {
  lx = (lx>>n)|((__uint32_t)hx<<(32-n));
  hx >>= n;
     } else if (n<=31) {
  lx = (hx<<(32-n))|(lx>>n); hx = sx;
     } else {
  lx = hx>>(n-32); hx = sx;
     }
     do { ieee_double_shape_type iw_u; iw_u.parts.msw = (hx|sx); iw_u.parts.lsw = (lx); (x) = iw_u.value; } while (0);
     x *= one;
 }
 return x;
}


double floor_double(double x) {
 __int32_t i0,i1,j0;
 __uint32_t i,j;
 do { ieee_double_shape_type ew_u; ew_u.value = (x); (i0) = ew_u.parts.msw; (i1) = ew_u.parts.lsw; } while (0);
 j0 = ((i0>>20)&0x7ff)-0x3ff;
 if(j0<20) {
     if(j0<0) {
  if(huge+x>0.0) {
      if(i0>=0) {i0=i1=0;}
      else if(((i0&0x7fffffff)|i1)!=0)
   { i0=0xbff00000;i1=0;}
  }
     } else {
  i = (0x000fffff)>>j0;
  if(((i0&i)|i1)==0) return x;
  if(huge+x>0.0) {
      if(i0<0) i0 += (0x00100000)>>j0;
      i0 &= (~i); i1=0;
  }
     }
 } else if (j0>51) {
     if(j0==0x400) return x+x;
     else return x;
 } else {
     i = ((__uint32_t)(0xffffffff))>>(j0-20);
     if((i1&i)==0) return x;
     if(huge+x>0.0) {
  if(i0<0) {
      if(j0==20) i0+=1;
      else {
   j = i1+(1<<(52-j0));
   if(j<i1) i0 +=1 ;
   i1=j;
      }
  }
  i1 &= (~i);
     }
 }
 do { ieee_double_shape_type iw_u; iw_u.parts.msw = (i0); iw_u.parts.lsw = (i1); (x) = iw_u.value; } while (0);
 return x;
}



double fabs_double(double x) {
 __uint32_t high;
 do { ieee_double_shape_type gh_u; gh_u.value = (x); (high) = gh_u.parts.msw; } while (0);
 do { ieee_double_shape_type sh_u; sh_u.value = (x); sh_u.parts.msw = (high&0x7fffffff); (x) = sh_u.value; } while (0);
        return x;
}

/*
 * returns 1 if x is an integer.
 * returns false for NaNs (NaNs always compare unequal)
 * returns true for +-infinity,
 * floorf does not have the problem with overflowing the integer type used to hold the truncated result, because floorf() returns a float.
 */
int isinteger_double(double x){
  return (floor_double(x) == x);
}


static const double atanhi[] = {
  4.63647609000806093515e-01,
  7.85398163397448278999e-01,
  9.82793723247329054082e-01,
  1.57079632679489655800e+00,
};


static const double atanlo[] = {
  2.26987774529616870924e-17,
  3.06161699786838301793e-17,
  1.39033110312309984516e-17,
  6.12323399573676603587e-17,
};


static const double aT[] = {
  3.33333333333329318027e-01,
 -1.99999999998764832476e-01,
  1.42857142725034663711e-01,
 -1.11111104054623557880e-01,
  9.09088713343650656196e-02,
 -7.69187620504482999495e-02,
  6.66107313738753120669e-02,
 -5.83357013379057348645e-02,
  4.97687799461593236017e-02,
 -3.65315727442169155270e-02,
  1.62858201153657823623e-02,
};


double atan_double(double x) {
 double w,s1,s2,z;
 __int32_t ix,hx,id;

 do { ieee_double_shape_type gh_u; gh_u.value = (x); (hx) = gh_u.parts.msw; } while (0);
 ix = hx&0x7fffffff;
 if(ix>=0x44100000) {
     __uint32_t low;
     do { ieee_double_shape_type gl_u; gl_u.value = (x); (low) = gl_u.parts.lsw; } while (0);
     if(ix>0x7ff00000||
  (ix==0x7ff00000&&(low!=0)))
  return x+x;
     if(hx>0) return atanhi[3]+atanlo[3];
     else return -atanhi[3]-atanlo[3];
 } if (ix < 0x3fdc0000) {
     if (ix < 0x3e200000) {
  if(huge+x>one) return x;
     }
     id = -1;
 } else {
 x = fabs_double(x);
 if (ix < 0x3ff30000) {
     if (ix < 0x3fe60000) {
  id = 0; x = (2.0*x-one)/(2.0+x);
     } else {
  id = 1; x = (x-one)/(x+one);
     }
 } else {
     if (ix < 0x40038000) {
  id = 2; x = (x-1.5)/(one+1.5*x);
     } else {
  id = 3; x = -1.0/x;
     }
 }}

 z = x*x;
 w = z*z;

 s1 = z*(aT[0]+w*(aT[2]+w*(aT[4]+w*(aT[6]+w*(aT[8]+w*aT[10])))));
 s2 = w*(aT[1]+w*(aT[3]+w*(aT[5]+w*(aT[7]+w*aT[9]))));
 if (id<0) return x - x*(s1+s2);
 else {
     z = atanhi[id] - ((x*(s1+s2) - atanlo[id]) - x);
     return (hx<0)? -z:z;
 }
}
