CC = gcc
CFLAGS = -c -O0 -I../libs/newlib/libc/include/
LD = $(CC)
LDFLAGS = -lm

TARGET = .

SRCS = $(shell find . -type f -iname '*.c')
OBJS = $(shell find . -type f -iname '*.o')

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(PROGS) $(OBJS)
