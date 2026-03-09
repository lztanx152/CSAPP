//
// Created by root on 2026/3/5.
//

long mult2(long, long);

void multsore(long x, long y, long *dest)
{
    long t  = mult2(x,y);
    *dest = t;
}

// gcc -Og -S mstore.c
// gcc -Og -c mstore.c
// objdump -d mstore.o