//
// Created by root on 2026/1/18.
//
#include <stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf (" %.2x", start [i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float (float x) {
    show_bytes ((byte_pointer) &x, sizeof (float));
}
void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

void test_oversize(void)
{
    const int a = 500 * 400 * 300 * 200;
    printf("500 *400*300*200: %i\n", a);
    const float f1 = 3.14 + 1e20 - 1e20;
    printf("3.14 + 1e20 - 1e20: %f\n", f1);
    const float f2 = 3.14 + (1e20 - 1e20);
    printf("3.14 + (1e20 - 1e20): %f\n", f2);
    const int test_endian = 0x12345678;
    printf("test_endian: %i\n", test_endian);
}

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void test_inplace_swap()
{
    int x = 10;
    int y = 20;
    inplace_swap(&x, &y);
    printf("x = %i, y = %i\n", x, y);
}

void short_to_unsigned()
{
    short sx = -12345;
    unsigned usx = sx;
    printf("usx = %i\n", usx);
    show_bytes((byte_pointer) &usx, sizeof(unsigned));
}

int main()
{
    test_oversize();
    test_show_bytes(12345);
    show_bytes("12345", 6);
    test_inplace_swap();
    int test = 12;
    inplace_swap(&test, &test);
    printf("test = %i\n", test);
    short_to_unsigned();
}
