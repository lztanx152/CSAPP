//
// Created by root on 2026/1/21.
//
#include <stdbool.h>
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
//2.61 start
int solution_2_61_a(int x)
{
    return !~x;
}
int solution_2_61_b(int x)
{
    return !x;
}
int solution_2_61_c(int x)
{
    return !(~x & 0xFF);
}
int solution_2_61_d(int x)
{
    return !(x & 0xFF000000);
}
void ex_2_61()
{
    printf("----------- Solution of 2.61 start ---------------\n");
    printf("test A, %x is %d \n",0xFFFFFFFF, solution_2_61_a(0xFFFFFFFF));
    printf("test A, %x is %d \n",0xFFFFFFF0, solution_2_61_a(0xFFFFFFF0));
    printf("test B, %x is %d \n",0xFFFFFFF0, solution_2_61_b(0xFFFFFFF0));
    printf("test B, %x is %d \n",0x00000000, solution_2_61_b(0x00000000));
    printf("test C, %x is %d \n",0x000000F0, solution_2_61_c(0x000000F0));
    printf("test C, %x is %d \n",0xFF, solution_2_61_c(0xFF));
    printf("test D, %x is %d \n",0xFF0000FF, solution_2_61_d(0xFF0000FF));
    printf("test D, %x is %d \n",0xF00000FF, solution_2_61_d(0xF00000FF));
    printf("test D, %x is %d \n",0x000000FF, solution_2_61_d(0x000000FF));
    printf("----------- Solution of 2.61 end ---------------\n");
}
//2.61 end
//2.62 start
int int_shifts_are_arithmetic()
{
    return 0xff000000 >> (sizeof(int)*8 - 1) & 0x00000001;
}
void ex_2_62()
{
    printf("----------- Solution of 2.62 start ---------------\n");
    printf("int_shifts_are_arithmetic: %x\n", int_shifts_are_arithmetic());
    printf("----------- Solution of 2.62 end ---------------\n");
}
//2.62 end
//2.63 start
unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int) x >> k;
    xsra = xsra & ~(0xffffffff << (8*sizeof(int) - k));
    return xsra;
}
// ****
int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    int w = sizeof(int) * 8;
    int mask = 0xffffffff << (w - k);
    int m = 1 << (w - 1);
    // 核心是根据x的正负性质获取掩码
    // 0-1的得到全1，1-1为0
    mask &= ! (x & m) - 1;
    return xsrl | mask;
}

void ex_2_63()
{
    printf("----------- Solution of 2.63 start ---------------\n");
    printf("SRL of %b by %d is %b\n", -1, 12, srl((unsigned)-1, 12));
    printf("SRL of %b by %d is %b\n", 1,  12, srl((unsigned)1, 12));
    printf("SRA of %b by %d is %b\n", -100000,  12, sra(-100000, 12));
    printf("SRA of %b by %d is %b\n", 1,  12, sra(1, 12));
    printf("----------- Solution of 2.63 end ---------------\n");
}
//2.63 end
//2.64 start
// x的任何奇数位置为1时返回1，其他为0
int any_odd_one(unsigned x)
{
    return (bool)(x & 0xAAAAAAAA);
}
void ex_2_64()
{
    printf("----------- Solution of 2.64 start ---------------\n");
    printf("any_odd_one:%x\n", any_odd_one(0));
    printf("any_odd_one:%x\n", any_odd_one(1));
    printf("any_odd_one:%x\n", any_odd_one(2));
    printf("----------- Solution of 2.64 end ---------------\n");
}
//2.64 end
//2.65 start
// x中若有奇数个1返回1，否则0
// 涉及异或的理解：按位无进位加法
// 异或运算可以统计1的个数
// ****
int odd_ones(unsigned x)
{
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    x &= 0x1;
    return x;
}
void ex_2_65()
{
    printf("----------- Solution of 2.65 start ---------------\n");
    printf("odd_ones:%x\n", odd_ones(0b101));
    printf("odd_ones:%x\n", odd_ones(0b1011));
    printf("----------- Solution of 2.65 end ---------------\n");
}
//2.65 end
int main()
{
    ex_2_57();
    ex_2_58();
    ex_2_59();
    ex_2_60();
    ex_2_61();
    ex_2_62();
    ex_2_63();
    ex_2_64();
    ex_2_65();
}