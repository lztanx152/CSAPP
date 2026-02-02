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
//2.59 start
// 先判断大小端,再merge
int merge_two_nums_version1(int num1, int num2)
{
    int res = num2;
    char *p = (char *)&res;
    if (is_little_endian() == 1)
    {
        *p = *(char *)&num1;
    } else
    {
        *(p + 3) = *((char *)&num1 + 3);
    }
    return res;
}
// 按位置操作
int merge_two_nums_version2(int num1, int num2)
{
    return (num2 & 0xffffff00) | (num1 & 0xff);
}
void ex_2_59() {
    printf("----------- Solution of 2.59 start ---------------\n");
    printf("result of merging %x and %x is %x \n", 0x89abcdef, 0x7654321, merge_two_nums_version1(0x89abcdef, 0x7654321));
    printf("result of merging %x and %x is %x \n", 0x89abcdef, 0x7654321, merge_two_nums_version2(0x89abcdef, 0x7654321));
    printf("----------- Solution of 2.59 end ---------------\n");
}
//2.59 end
//2.60 start
unsigned replace_byte (unsigned x, int i, unsigned char b)
{
    char *p = (char *)&x;
    if (is_little_endian())
    {
        *(p + i) = b;
    } else
    {
        *(p + sizeof(unsigned) - 1 - i) = b;
    }
    return x;
}
void ex_2_60()
{
    printf("----------- Solution of 2.60 start ---------------\n");
    printf("%x, %d, %x: %x\n", 0x12345678, 2, 0xAB, replace_byte(0x12345678, 2, 0xAB));
    printf("%x, %d, %x: %x\n", 0x12345678, 0, 0xAB, replace_byte(0x12345678, 0, 0xAB));
    printf("----------- Solution of 2.60 end ---------------\n");
}
//2.60 end
int main()
{
    ex_2_57();
    ex_2_58();
    ex_2_59();
    ex_2_60();
}