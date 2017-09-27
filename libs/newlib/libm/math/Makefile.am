## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = cygnus

INCLUDES = -I$(srcdir)/../common $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)

src = 	k_rem_pio2.c \
	k_cos.c k_sin.c k_tan.c \
	e_acos.c e_asin.c e_atan2.c \
	e_exp.c e_fmod.c \
	e_hypot.c \
	e_log.c e_log10.c e_pow.c e_rem_pio2.c \
	e_sqrt.c \
	w_acos.c w_asin.c w_atan2.c \
	w_exp.c w_fmod.c \
	w_hypot.c \
	w_log.c w_log10.c w_pow.c \
	w_sqrt.c \
	s_atan.c s_ceil.c \
	s_cos.c s_fabs.c s_floor.c \
	s_sin.c \
	s_tan.c


fsrc =	kf_rem_pio2.c \
	kf_cos.c kf_sin.c kf_tan.c \
	ef_acos.c ef_asin.c ef_atan2.c \
	ef_exp.c ef_fmod.c \
	ef_hypot.c \
	ef_log.c ef_log10.c ef_pow.c ef_rem_pio2.c \
	ef_sqrt.c \
	wf_acos.c wf_asin.c wf_atan2.c \
	wf_exp.c wf_fmod.c \
	wf_hypot.c \
	wf_log.c wf_log10.c wf_pow.c \
	wf_sqrt.c \
	sf_atan.c sf_ceil.c \
	sf_cos.c sf_fabs.c sf_floor.c \
	sf_sin.c \
	sf_tan.c

libmath_la_LDFLAGS = -Xcompiler -nostdlib

if USE_LIBTOOL
noinst_LTLIBRARIES = libmath.la
libmath_la_SOURCES = $(src) $(fsrc)
noinst_DATA = objectlist.awk.in
else
noinst_LIBRARIES = lib.a
lib_a_SOURCES = $(src) $(fsrc)
lib_a_CFLAGS = $(AM_CFLAGS)
noinst_DATA =
endif # USE_LIBTOOL

include $(srcdir)/../../Makefile.shared

CHEWOUT_FILES = w_acos.def w_asin.def \
	s_atan.def w_atan2.def \
	w_exp.def \
	s_fabs.def s_floor.def w_fmod.def \
	w_hypot.def w_log.def \
	w_log10.def \
	w_pow.def s_sin.def \
	w_sqrt.def s_tan.def

CHAPTERS = math.tex

# A partial dependency list.

$(lib_a_OBJECTS): $(srcdir)/../../libc/include/math.h $(srcdir)/../common/fdlibm.h
