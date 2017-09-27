CC = gcc -E
LIBS  = -lm
CFLAGS = -Wall
INCLUDE = -I../../libc/include/ -I../../libc/include/machine -I../common/

SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%.i,$(SRCS))

all: $(PROGS)

%.i: %.c
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDE) -o $@ $<

clean:
	rm -f $(PROGS)
