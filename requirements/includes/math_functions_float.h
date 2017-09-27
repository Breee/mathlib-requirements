/*
* preprocessed newlib functions
*/

// Constants
static const float onesqrt = 1.0;
static const float bp[] = {1.0, 1.5,},
dp_h[] = { 0.0, 5.84960938e-01,},
dp_l[] = { 0.0, 1.56322085e-06,},
zero = 0.0,
one = 1.0,
two = 2.0,
two24 = 16777216.0,
huge = 1.0e30,
tiny = 1.0e-30,
L1 = 6.0000002384e-01,
L2 = 4.2857143283e-01,
L3 = 3.3333334327e-01,
L4 = 2.7272811532e-01,
L5 = 2.3066075146e-01,
L6 = 2.0697501302e-01,
P1 = 1.6666667163e-01,
P2 = -2.7777778450e-03,
P3 = 6.6137559770e-05,
P4 = -1.6533901999e-06,
P5 = 4.1381369442e-08,
lg2 = 6.9314718246e-01,
lg2_h = 6.93145752e-01,
lg2_l = 1.42860654e-06,
ovt = 4.2995665694e-08,
cp = 9.6179670095e-01,
cp_h = 9.6179199219e-01,
cp_l = 4.7017383622e-06,
ivln2 = 1.4426950216e+00,
ivln2_h = 1.4426879883e+00,
ivln2_l = 7.0526075433e-06;

static const float Zero[] = {0.0, -0.0,};

static const float two25 = 3.355443200e+07,
twom25 = 2.9802322388e-08;



// infinity check for floats
int isinf_float(float x) {
 __int32_t ix;
 do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
 ix &= 0x7fffffff;
 return ((ix)==0x7f800000L);
}


// nan check for floats
int isnan_float(float x) {
 #if defined(ULTIMATE)
   return x != x;
 #else
   __int32_t ix;
   do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
   ix &= 0x7fffffff;
   return ((ix)>0x7f800000L);
 #endif
}


// check if value is finite
int isfinite_float(float x) {
__int32_t ix;
do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
ix &= 0x7fffffff;
return (((ix)<0x7f800000L));
}


/*
 * __fpclassify Categorizes floating point value arg into the following categories:
 * zero, subnormal, normal, infinite, NAN, or implementation-defined category.
 * Returns One of FP_INFINITE, FP_NAN, FP_NORMAL, FP_SUBNORMAL, FP_ZERO or implementation-defined type, specifying the category of arg.
 */


int __fpclassifyf (float x) {
  __uint32_t w;

  do { ieee_float_shape_type gf_u; gf_u.value = (x); (w) = gf_u.word; } while (0);

  if (w == 0x00000000 || w == 0x80000000)
    return 2;
  else if ((w >= 0x00800000 && w <= 0x7f7fffff) ||
           (w >= 0x80800000 && w <= 0xff7fffff))
    return 4;
  else if ((w >= 0x00000001 && w <= 0x007fffff) ||
           (w >= 0x80000001 && w <= 0x807fffff))
    return 3;
  else if (w == 0x7f800000 || w == 0xff800000)
    return 1;
  else
    return 0;
}


float copysign_float(float x, float y) {
__uint32_t ix,iy;
do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
do { ieee_float_shape_type gf_u; gf_u.value = (y); (iy) = gf_u.word; } while (0);
do { ieee_float_shape_type sf_u; sf_u.word = ((ix&0x7fffffff)|(iy&0x80000000)); (x) = sf_u.value; } while (0);
       return x;
}

float scalbn_float(float x, int n) {
 __int32_t k,ix;
 __uint32_t hx;

 do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
 hx = ix&0x7fffffff;
        k = hx>>23;
 if (((hx)==0))
     return x;
        if (!((hx)<0x7f800000L))
     return x+x;
        if (((hx)<0x00800000L)) {
     x *= two25;
     do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
     k = ((ix&0x7f800000)>>23) - 25;
            if (n< -50000) return tiny*x;
        }
        k = k+n;
        if (k > (0x7f7fffffL>>23)) return huge*copysign_float(huge,x);
        if (k > 0)
     {do { ieee_float_shape_type sf_u; sf_u.word = ((ix&0x807fffff)|(k<<23)); (x) = sf_u.value; } while (0); return x;}
        if (k < -22) {
            if (n > 50000)
  return huge*copysign_float(huge,x);
     else return tiny*copysign_float(tiny,x);
        }
        k += 25;
 do { ieee_float_shape_type sf_u; sf_u.word = ((ix&0x807fffff)|(k<<23)); (x) = sf_u.value; } while (0);
        return x*twom25;
}


float __ieee754_sqrtf(float x) {
 float z;
 __uint32_t r,hx;
 __int32_t ix,s,q,m,t,i;

 do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
 hx = ix&0x7fffffff;


 if(!((hx)<0x7f800000L))
     return x*x+x;


 if(((hx)==0)) return x;
 if(ix<0) return (x-x)/(x-x);


 m = (ix>>23);
 if(((hx)<0x00800000L)) {
     for(i=0;(ix&0x00800000L)==0;i++) ix<<=1;
     m -= i-1;
 }
 m -= 127;
 ix = (ix&0x007fffffL)|0x00800000L;
 if(m&1)
     ix += ix;
 m >>= 1;


 ix += ix;
 q = s = 0;
 r = 0x01000000L;

 while(r!=0) {
     t = s+r;
     if(t<=ix) {
  s = t+r;
  ix -= t;
  q += r;
     }
     ix += ix;
     r>>=1;
 }


 if(ix!=0) {
     z = onesqrt-tiny;
     if (z>=onesqrt) {
         z = onesqrt+tiny;
  if (z>onesqrt)
      q += 2;
  else
      q += (q&1);
     }
 }
 ix = (q>>1)+0x3f000000L;
 ix += (m <<23);
 do { ieee_float_shape_type sf_u; sf_u.word = (ix); (z) = sf_u.value; } while (0);
 return z;
}


float fmod_float(float x, float y) {
 __int32_t n,hx,hy,hz,ix,iy,sx,i;

 do { ieee_float_shape_type gf_u; gf_u.value = (x); (hx) = gf_u.word; } while (0);
 do { ieee_float_shape_type gf_u; gf_u.value = (y); (hy) = gf_u.word; } while (0);
 sx = hx&0x80000000;
 hx ^=sx;
 hy &= 0x7fffffff;

 if(((hy)==0)||
    !((hx)<0x7f800000L)||
    ((hy)>0x7f800000L))
     return (x*y)/(x*y);
 if(hx<hy) return x;
 if(hx==hy)
     return Zero[(__uint32_t)sx>>31];

 if(((hx)<0x00800000L)) {
     for (ix = -126,i=(hx<<8); i>0; i<<=1) ix -=1;
 } else ix = (hx>>23)-127;


 if(((hy)<0x00800000L)) {
     for (iy = -126,i=(hy<<8); i>=0; i<<=1) iy -=1;
 } else iy = (hy>>23)-127;


 if(ix >= -126)
     hx = 0x00800000|(0x007fffff&hx);
 else {
     n = -126-ix;
     hx = hx<<n;
 }
 if(iy >= -126)
     hy = 0x00800000|(0x007fffff&hy);
 else {
     n = -126-iy;
     hy = hy<<n;
 }

 n = ix - iy;
 while(n--) {
     hz=hx-hy;
     if(hz<0){hx = hx+hx;}
     else {
      if(hz==0)
      return Zero[(__uint32_t)sx>>31];
      hx = hz+hz;
     }
 }
 hz=hx-hy;
 if(hz>=0) {hx=hz;}

 if(hx==0)
     return Zero[(__uint32_t)sx>>31];
 while(hx<0x00800000) {
     hx = hx+hx;
     iy -= 1;
 }
 if(iy>= -126) {
     hx = ((hx-0x00800000)|((iy+127)<<23));
     do { ieee_float_shape_type sf_u; sf_u.word = (hx|sx); (x) = sf_u.value; } while (0);
 } else {
     n = -126 - iy;
     hx >>= n;
     do { ieee_float_shape_type sf_u; sf_u.word = (hx|sx); (x) = sf_u.value; } while (0);
     x *= one;
 }
 return x;
}

float floor_float(float x) {
 __int32_t i0,j0;
 __uint32_t i,ix;
 do { ieee_float_shape_type gf_u; gf_u.value = (x); (i0) = gf_u.word; } while (0);
 ix = (i0&0x7fffffff);
 j0 = (ix>>23)-0x7f;
 if(j0<23) {
     if(j0<0) {
  if(huge+x>(float)0.0) {
      if(i0>=0) {i0=0;}
      else if(!((ix)==0))
   { i0=0xbf800000;}
  }
     } else {
  i = (0x007fffff)>>j0;
  if((i0&i)==0) return x;
  if(huge+x>(float)0.0) {
      if(i0<0) i0 += (0x00800000)>>j0;
      i0 &= (~i);
  }
     }
 } else {
     if(!((ix)<0x7f800000L)) return x+x;
     else return x;
 }
 do { ieee_float_shape_type sf_u; sf_u.word = (i0); (x) = sf_u.value; } while (0);
 return x;
}

float fabs_float(float x) {
__uint32_t ix;
do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
do { ieee_float_shape_type sf_u; sf_u.word = (ix&0x7fffffff); (x) = sf_u.value; } while (0);
       return x;
}

/*
 * returns 1 if x is an integer.
 * returns false for NaNs (NaNs always compare unequal)
 * returns true for +-infinity,
 * floorf does not have the problem with overflowing the integer type used to hold the truncated result, because floorf() returns a float.
 */
int isinteger_float(float x){
  return (floor_float(x) == x);
}
