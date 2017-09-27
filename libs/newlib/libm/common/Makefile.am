## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = cygnus

INCLUDES = $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)

src = 	s_finite.c s_copysign.c s_modf.c s_scalbn.c \
	s_isinf.c s_isnan.c \
	s_nan.c \
	s_rint.c s_matherr.c s_lib_ver.c \
	s_fmax.c s_fmin.c s_fpclassify.c \
	s_round.c \
	s_signbit.c s_trunc.c

fsrc =	sf_finite.c sf_copysign.c sf_modf.c sf_scalbn.c \
	sf_isinf.c sf_isnan.c \
	sf_nan.c \
	sf_rint.c \
	sf_fmax.c sf_fmin.c sf_fpclassify.c \
	sf_round.c \
	sf_trunc.c

libcommon_la_LDFLAGS = -Xcompiler -nostdlib

if USE_LIBTOOL
noinst_LTLIBRARIES = libcommon.la
libcommon_la_SOURCES = $(src) $(fsrc)
noinst_DATA = objectlist.awk.in
else
noinst_LIBRARIES = lib.a
lib_a_SOURCES = $(src) $(fsrc)
lib_a_CFLAGS = $(AM_CFLAGS)
noinst_DATA =
endif # USE_LIBTOOL

include $(srcdir)/../../Makefile.shared

CHEWOUT_FILES =	s_copysign.def \
	s_isnan.def s_matherr.def s_modf.def \
	s_nan.def s_scalbn.def \
	s_fmax.def s_fmin.def \
	s_rint.def s_round.def s_signbit.def s_trunc.def

CHAPTERS =

# A partial dependency list.

$(lib_a_OBJECTS): $(srcdir)/../../libc/include/math.h fdlibm.h
