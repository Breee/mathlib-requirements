#!/bin/bash
gcc -E -C -CC -I. -D__FRAMAC__ -I../../libs/newlib/libc/include/ test.c > test.i

# Maybe this is not needed: (what does -x c?)
gcc -E -x c -D__FRAMAC__ -CC -I../../libs/newlib/libc/include/ test.c > narf.c

sed -i narf.c -e "/^#.*/d"
