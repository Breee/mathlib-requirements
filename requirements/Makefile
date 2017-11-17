CC = gcc
CFLAGS = -O0 -I../libs/newlib/libc/include/ -DCOVERITY
LD = $(CC)

TARGET = .

SRCS = $(shell find . -type f -iname '*.c')
OBJS = $(shell find . -type f -iname '*.o')

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGS) $(OBJS)
