#
OUT = test
GCC = gcc
ARGS = -O0 -g -c
LIBS = -lm
INCLUDE = -I../../libs/newlib/libc/include/
SCAN_BUILD = scan-build-4.0
CBMC = cbmc
FRAMA_C = frama-c
INFER = infer

all : test

test : test.o
	$(GCC) test.o -g $(LIBS) -o $(OUT)

test.o :
	$(GCC) test.c $(INCLUDE) $(ARGS) $(LIBS)

test.i : test.c
	$(GCC) -E test.c $(INCLUDE) $(LIBS) -o test.i

scan : test.c
	$(SCAN_BUILD) $(GCC) test.c $(INCLUDE) $(ARGS) $(LIBS)

cbmc : test.c
	$(CBMC) $(INCLUDE) --show-properties --bounds-check --pointer-check test.c

frama-c : test.i
	$(FRAMA_C) -val test.i

infer: test.c
	$(INFER) -- $(GCC) test.c $(INCLUDE) $(ARGS) $(LIBS)

# add ultimate.

clean :
	rm $(OUT) $(OUT).o $(OUT).i

.PHONY: all clean
