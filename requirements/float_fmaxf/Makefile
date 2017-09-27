# call:  make FILE=xxx to build a specific .c file
# TODO: just build all binaries at once

FILES = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(FILES))

OUT = $(patsubst %.c,%,$(FILE))
OFILE = $(patsubst %.c,%.o,$(FILE))
IFILE = $(patsubst %.c,%.i,$(FILE))

GCC = gcc -O0 -g -Wall
LIBS =
INCLUDE = -I../../libs/newlib/libc/include/
CHECKERS=\
-enable-checker core.NullDereference \
-disable-checker core.uninitialized \
-enable-checker debug.ExprInspection \
-enable-checker alpha.core.BoolAssignment \
-enable-checker alpha.core.CallAndMessageUnInitRefArg \
-enable-checker alpha.core.CastSize \
-enable-checker alpha.core.CastToStruct \
-enable-checker alpha.core.Conversion \
-enable-checker alpha.core.DynamicTypeChecker \
-enable-checker alpha.core.FixedAddr \
-enable-checker alpha.core.IdenticalExpr \
-enable-checker alpha.core.PointerArithm \
-enable-checker alpha.core.PointerSub \
-enable-checker alpha.core.SizeofPtr \
-enable-checker alpha.core.TestAfterDivZero \
-enable-checker alpha.deadcode.UnreachableCode \
-enable-checker alpha.security.ArrayBoundV2 \
-enable-checker alpha.security.MallocOverflow \
-enable-checker alpha.security.ReturnPtrRange \
-enable-checker alpha.security.taint.TaintPropagation \
-enable-checker alpha.unix.BlockInCriticalSection \
-enable-checker alpha.unix.Chroot \
-enable-checker alpha.unix.PthreadLock \
-enable-checker alpha.unix.SimpleStream \
-enable-checker alpha.unix.Stream \
-enable-checker alpha.unix.cstring.BufferOverlap \
-enable-checker alpha.unix.cstring.NotNullTerminated \
-enable-checker alpha.unix.cstring.OutOfBounds \
-enable-checker alpha.valist.CopyToSelf \
-enable-checker alpha.valist.Unterminated \
-enable-checker nullability.NullableDereferenced \
-enable-checker nullability.NullablePassedToNonnull \
-enable-checker nullability.NullableReturnedFromNonnull \
-enable-checker optin.performance.Padding

SCAN_BUILD = scan-build-4.0 --show-description -v $(CHECKERS)
CBMC = cbmc
FRAMA_C = frama-c
INFER = infer
ULTIMATE_DIR = ~/programs/UAutomizer-linux/
KOJAK_DIR = ~/programs/UKojak-linux/
TAIPAN_DIR = ~/programs/UTaipan-linux/

all : test

test : $(OFILE)
	$(GCC) $(OFILE) -g $(LIBS) -DCLANG -o $(OUT)

$(OFILE) :
	$(GCC) $(FILE) $(INCLUDE) -c $(LIBS)

$(IFILE) : $(FILE)
	$(GCC) -E -CC $(FILE) $(INCLUDE) $(LIBS) -o $(IFILE)

scan : $(FILE)
	gcc -E -x c -DCLANG -CC -I../../libs/newlib/libc/include/ -lm $(FILE) > $(FILE).pre.c
	sed -i $(FILE).pre.c -e "/^#.*/d"
	$(SCAN_BUILD) $(GCC) -lm -c $(FILE).pre.c

cbmc : $(FILE)
	$(CBMC) $(INCLUDE) --bounds-check --div-by-zero-check --pointer-check --memory-leak-check --signed-overflow-check --unsigned-overflow-check --float-overflow-check --nan-check --function main -DCBMC $(FILE)

frama-c :
	gcc -E -x c -DFRAMAC -CC -I../../libs/newlib/libc/include/ -lm $(FILE) > $(FILE).pre.c
	sed -i $(FILE).pre.c -e "/^#.*/d"
	$(FRAMA_C) -rte -rte-all -wp -wp-rte -wp-status-all -wp-model 'Hoare' $(FILE).pre.c

infer: $(FILE)
	$(INFER) -- $(GCC) -DCLANG $(INCLUDE) $(LIBS) -c $(FILE)

# add ultimate.
ultimate:
	gcc -E -x c -DULTIMATE -CC -I../../libs/newlib/libc/include/ -lm $(FILE) > $(FILE).pre.c
	sed -i $(FILE).pre.c -e "/^#.*/d"
	cd $(ULTIMATE_DIR) && python2.7 $(ULTIMATE_DIR)Ultimate.py --spec $(ULTIMATE_DIR)property/PropertyUnreachCall.prp --file $(abspath $(FILE)).pre.c --architecture 64bit --full-output

check-precond: $(FILE)
	$(SCAN_BUILD) $(GCC) -DCHECK_PRECOND $(INCLUDE) $(LIBS) -c $(FILE)
	$(CBMC) $(INCLUDE) --bounds-check --div-by-zero-check --pointer-check --memory-leak-check --signed-overflow-check --unsigned-overflow-check --float-overflow-check --nan-check --function main -DCHECK_PRECOND $(FILE)


clean :
	rm -f $(PROGS) *.o *.i *.log *.c.pre.c



.PHONY: all clean
