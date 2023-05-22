#!/bin/bash
gcc -Wall -Wextra -Werror -padantic -c -fPIC *.c
gcc -shared -o liball.so *.o
export LD_LIBRAY_PATH=.:$LD_LIBRARY_PATH
