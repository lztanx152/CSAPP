//
// Created by root on 2026/1/25.
//

#include <stdio.h>
// 2.13 start
int bis(int x, int m)
{
    return x | m;
}

int bic(int x, int m)
{
    return x & ~ m;
}

int bool_or(int x, int y) {
    int result =bis(x,y);
    return result;
}
int bool_xor(int x, int y)
{
    int result= bis(bic(x,y), bic(y,x));
    return result;
}
// 2.13 end
int main()
{
    printf("%d\n", 1e20*1e20 - 1e20*1e20);
}