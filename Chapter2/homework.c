//
// Created by root on 2026/1/21.
//
#include <stdio.h>

// 2.55 略
// 2.56 略
// 2.57 start
void show_short(short n)
{
    printf("num is %d----------\n", n);
    unsigned char *p = &n;
    for (int i = 0; i < sizeof(short); i++)
    {
        printf("%d\n", p[i]);
    }
    printf("end ---------\n");
}
void show_long(long n)
{
    printf("num is %ld----------\n", n);
    unsigned char *p = &n;
    for (int i = 0; i < sizeof(long); i++)
    {
        printf("%d\n", p[i]);
    }
    printf("end ---------\n");
}
void show_double(double n)
{
    printf("num is %f----------\n", n);
    unsigned char *p = &n;
    for (int i = 0; i < sizeof(double); i++)
    {
        printf("%d\n", p[i]);
    }
    printf("end ---------\n");
}
void ex_2_57()
{
    printf("----------- Solution of 2.57 start -------------------\n");
    show_short(12435);
    show_long(124356789);
    show_double(12435.6789);
    printf("----------- Solution of 2.57 end   -------------------\n");
}
// 2.57 end
// 2.58 start
int is_little_endian()
{
    int num = 0x1234;
    unsigned char *p = (unsigned char *)&num;
    if (*p == 0x34)
    {
        return 1;
    } else
    {
        return 0;
    }
}
void ex_2_58()
{
    printf("----------- Solution of 2.58 start -------------------\n");
    if (is_little_endian() == 1)
    {
        printf("Little Endian\n");
    } else
    {
        printf("Big Endian\n");
    }
    printf("----------- Solution of 2.58 end   -------------------\n");
}
//2.58 end
int main()
{
    ex_2_57();
    ex_2_58();
}