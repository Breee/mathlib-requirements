float __ieee754_powf(float x, float y) {
 float z,ax,z_h,z_l,p_h,p_l;
 float y1,t1,t2,r,s,t,u,v,w;
 __int32_t i,j,k,yisint,n;
 __int32_t hx,hy,ix,iy,is;

 do { ieee_float_shape_type gf_u; gf_u.value = (x); (hx) = gf_u.word; } while (0);
 do { ieee_float_shape_type gf_u; gf_u.value = (y); (hy) = gf_u.word; } while (0);
 ix = hx&0x7fffffff; iy = hy&0x7fffffff;


 if(((iy)==0)) return one;


 if(((ix)>0x7f800000L) ||
    ((iy)>0x7f800000L)) {
     if(ix==0x3f800000) return one;
     else return nanf("");
 }
 yisint = 0;
 if(hx<0) {
     if(iy>=0x4b800000) yisint = 2;
     else if(iy>=0x3f800000) {
  k = (iy>>23)-0x7f;
  j = iy>>(23-k);
  if((j<<(23-k))==iy) yisint = 2-(j&1);
     }
 }


 if (((iy)==0x7f800000L)) {
     if (ix==0x3f800000)
  return one;
     else if (ix > 0x3f800000)
         return (hy>=0)? y: zero;
     else
         return (hy<0)?-y: zero;
 }
 if(iy==0x3f800000) {
     if(hy<0) return one/x; else return x;
 }
 if(hy==0x40000000) return x*x;
 if(hy==0x3f000000) {
     if(hx>=0)
     return __ieee754_sqrtf(x);
 }

 ax = fabsf(x);

 if(((ix)==0x7f800000L)||((ix)==0)||ix==0x3f800000){
     z = ax;
     if(hy<0) z = one/z;
     if(hx<0) {
  if(((ix-0x3f800000)|yisint)==0) {
      z = (z-z)/(z-z);
  } else if(yisint==1)
      z = -z;
     }
     return z;
 }

 if(((((__uint32_t)hx>>31)-1)|yisint)==0) return (x-x)/(x-x);
 if(iy>0x4d000000) {
     if(ix<0x3f7ffff8) return (hy<0)? huge*huge:tiny*tiny;
     if(ix>0x3f800007) return (hy>0)? huge*huge:tiny*tiny;
     t = ax-1;
     w = (t*t)*((float)0.5-t*((float)0.333333333333-t*(float)0.25));
     u = ivln2_h*t;
     v = t*ivln2_l-w*ivln2;
     t1 = u+v;
     do { ieee_float_shape_type gf_u; gf_u.value = (t1); (is) = gf_u.word; } while (0);
     do { ieee_float_shape_type sf_u; sf_u.word = (is&0xfffff000); (t1) = sf_u.value; } while (0);
     t2 = v-(t1-u);
 } else {
     float s2,s_h,s_l,t_h,t_l;
     n = 0;
     if(((ix)<0x00800000L))
  {ax *= two24; n -= 24; do { ieee_float_shape_type gf_u; gf_u.value = (ax); (ix) = gf_u.word; } while (0); }
     n += ((ix)>>23)-0x7f;
     j = ix&0x007fffff;
     ix = j|0x3f800000;
     if(j<=0x1cc471) k=0;
     else if(j<0x5db3d7) k=1;
     else {k=0;n+=1;ix -= 0x00800000;}
     do { ieee_float_shape_type sf_u; sf_u.word = (ix); (ax) = sf_u.value; } while (0);
     u = ax-bp[k];
     v = one/(ax+bp[k]);
     s = u*v;
     s_h = s;
     do { ieee_float_shape_type gf_u; gf_u.value = (s_h); (is) = gf_u.word; } while (0);
     do { ieee_float_shape_type sf_u; sf_u.word = (is&0xfffff000); (s_h) = sf_u.value; } while (0);
     do { ieee_float_shape_type sf_u; sf_u.word = (((ix>>1)|0x20000000)+0x0040000+(k<<21)); (t_h) = sf_u.value; } while (0);
     t_l = ax - (t_h-bp[k]);
     s_l = v*((u-s_h*t_h)-s_h*t_l);
     s2 = s*s;
     r = s2*s2*(L1+s2*(L2+s2*(L3+s2*(L4+s2*(L5+s2*L6)))));
     r += s_l*(s_h+s);
     s2 = s_h*s_h;
     t_h = (float)3.0+s2+r;
     do { ieee_float_shape_type gf_u; gf_u.value = (t_h); (is) = gf_u.word; } while (0);
     do { ieee_float_shape_type sf_u; sf_u.word = (is&0xfffff000); (t_h) = sf_u.value; } while (0);
     t_l = r-((t_h-(float)3.0)-s2);
     u = s_h*t_h;
     v = s_l*t_h+t_l*s;
     p_h = u+v;
     do { ieee_float_shape_type gf_u; gf_u.value = (p_h); (is) = gf_u.word; } while (0);
     do { ieee_float_shape_type sf_u; sf_u.word = (is&0xfffff000); (p_h) = sf_u.value; } while (0);
     p_l = v-(p_h-u);
     z_h = cp_h*p_h;
     z_l = cp_l*p_h+p_l*cp+dp_l[k];
     t = (float)n;
     t1 = (((z_h+z_l)+dp_h[k])+t);
     do { ieee_float_shape_type gf_u; gf_u.value = (t1); (is) = gf_u.word; } while (0);
     do { ieee_float_shape_type sf_u; sf_u.word = (is&0xfffff000); (t1) = sf_u.value; } while (0);
     t2 = z_l-(((t1-t)-dp_h[k])-z_h);
 }
 s = one;
 if(((((__uint32_t)hx>>31)-1)|(yisint-1))==0)
     s = -one;
 do { ieee_float_shape_type gf_u; gf_u.value = (y); (is) = gf_u.word; } while (0);
 do { ieee_float_shape_type sf_u; sf_u.word = (is&0xfffff000); (y1) = sf_u.value; } while (0);
 p_l = (y-y1)*t1+y*t2;
 p_h = y1*t1;
 z = p_l+p_h;
 do { ieee_float_shape_type gf_u; gf_u.value = (z); (j) = gf_u.word; } while (0);
 i = j&0x7fffffff;
 if (j>0) {
     if (i>0x43000000)
         return s*huge*huge;
     else if (i==0x43000000)
         if(p_l+ovt>z-p_h) return s*huge*huge;
        } else {
     if (i>0x43160000)
         return s*tiny*tiny;
     else if (i==0x43160000)
         if(p_l<=z-p_h) return s*tiny*tiny;
 }

 k = (i>>23)-0x7f;
 n = 0;
 if(i>0x3f000000) {
     n = j+(0x00800000>>(k+1));
     k = ((n&0x7fffffff)>>23)-0x7f;
     do { ieee_float_shape_type sf_u; sf_u.word = (n&~(0x007fffff>>k)); (t) = sf_u.value; } while (0);
     n = ((n&0x007fffff)|0x00800000)>>(23-k);
     if(j<0) n = -n;
     p_h -= t;
 }
 t = p_l+p_h;
 do { ieee_float_shape_type gf_u; gf_u.value = (t); (is) = gf_u.word; } while (0);
 do { ieee_float_shape_type sf_u; sf_u.word = (is&0xfffff000); (t) = sf_u.value; } while (0);
 u = t*lg2_h;
 v = (p_l-(t-p_h))*lg2+t*lg2_l;
 z = u+v;
 w = v-(z-u);
 t = z*z;
 t1 = z - t*(P1+t*(P2+t*(P3+t*(P4+t*P5))));
 r = (z*t1)/(t1-two)-(w+z*w);
 z = one-(r-z);
 do { ieee_float_shape_type gf_u; gf_u.value = (z); (j) = gf_u.word; } while (0);
 j += (n<<23);
 if((j>>23)<=0) z = scalbn_float(z,(int)n);
 else do { ieee_float_shape_type sf_u; sf_u.word = (j); (z) = sf_u.value; } while (0);
 return s*z;
}
