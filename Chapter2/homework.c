//
// Created by root on 2026/1/21.
//
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
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
// 异或运算可以统计1的个数（递归）
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
//2.66 start
// 返回一个能指示最左边的1的掩码
// ****
int leftmost_one(unsigned x)
{
    // 思路，先把x最高位1后面全部填充为0，再右移+1
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return (x >> 1) + (x && 1);
}
void ex_2_66()
{
    printf("----------- Solution of 2.66 start ---------------\n");
    printf("leftmost_one:%x of %x\n", leftmost_one(0x1), 0x1);
    printf("leftmost_one:%x of %x\n", leftmost_one(0x66), 0x66);
    printf("----------- Solution of 2.66 end ---------------\n");
}
//2.66 end
//2.67 start
//A: 左移的位数不应该大于等于数值的长度
//B:在至少32位的机器上运行
int int_size_is_32_B()
{
    int x = 1<<31;
    int y = x<<1;
    // int至少是32位置，先移动31位，再移动1位，如果是32位，那么移动之后必为0
    return !y;
}
int int_size_is_32_C()
{
    int x = 1<<15;
    int x1 = x<<15;
    int y = x1<<2;
    // 原理跟上面类似，无法一次性移动大于等于数字位数的位数，就拆开移动
    return !y;
}

void ex_2_67()
{
    printf("----------- Solution of 2.67 start ---------------\n");
    printf("int_size_is_32_B:%x\n", int_size_is_32_B());
    printf("int_size_is_32_C:%x\n", int_size_is_32_C());
    printf("----------- Solution of 2.67 end ---------------\n");
}
//2.67 end
//2.68 start
// 生成右边n个1的掩码,n>=1
int lower_one_mask(int n)
{   // 先获取最高位为1后面n-1个0的数字，再进行填充
    int x = 0;
    x = (unsigned)1 << (n - 1);
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x;
}
void ex_2_68()
{
    printf("----------- Solution of 2.68 start ---------------\n");
    printf("for %d,lower_one_mask:%x\n",1, lower_one_mask(1));
    printf("for %d,lower_one_mask:%x\n",6, lower_one_mask(6));
    printf("for %d,lower_one_mask:%x\n",17, lower_one_mask(17));
    printf("for %d,lower_one_mask:%x\n",32, lower_one_mask(32));
    printf("----------- Solution of 2.68 end ---------------\n");
}
//2.68 end
//2.69 start
unsigned rotate_left(unsigned x, int n)
{
    return (x << n) | (x >> (32 - n));
}
void ex_2_69()
{
    printf("----------- Solution of 2.69 start ---------------\n");
    printf("for %x, %d, rotate_left:%x\n",0x12345678,4, rotate_left(0x12345678, 4));
    printf("for %x, %d, rotate_left:%x\n",0x12345678,20, rotate_left(0x12345678, 20));
    printf("for %x, %d, rotate_left:%x\n",0x12345678,0, rotate_left(0x12345678, 0));
    printf("----------- Solution of 2.69 end ---------------\n");
}
//2.69 end
//2.70 start
// 当x可以被表示为n比特二进制补码时返回1，否则0 1<=n<=w
int fits_bits(int x, int n)
{
// 核心是x大于0的时候，左数倒数第1个0在内和左边的位数要小于等于n
    // 负数的话换成右边
    //下面的逻辑是：正数的情况下，如果不够，左移会丢掉0，负数的话，会丢掉1
    return x<< (sizeof(int) * 8 - n) >> (sizeof(int) * 8 - n) == x;
}
void ex_2_70()
{
    printf("----------- Solution of 2.70 start ---------------\n");
    printf("for %b, %d, fits_bits:%d\n",0b11000010,5, fits_bits(0b11000010, 5));
    printf("for %b, %d, fits_bits:%d\n",0b000010,5, fits_bits(0b000010, 5));
    printf("----------- Solution of 2.70 end ---------------\n");
}
//2.70 end
//2.71 start
//A:未考虑负数
int xbyte(unsigned x, int bytenum)
{
    // 两种办法
    // 先左移再右移，自动完成符号扩展
    // return (int) x << ((3 - bytenum) * 8) >> (3 * 8);
    // 利用c语言强制转换
    return (int)(char)((x >> (bytenum * 8)) & 0xff);
}
void ex_2_71()
{
    printf("----------- Solution of 2.71 start ---------------\n");
    printf("for %x and %d is %x\n",0x12345678, 0, xbyte(0x12345678, 0));
    printf("for %x and %d is %x\n",0x12345678, 1, xbyte(0x12345678, 1));
    printf("for %x and %d is %x\n",0x12345678, 2, xbyte(0x12345678, 2));
    printf("for %x and %d is %x\n",0x12345678, 3, xbyte(0x12345678, 3));
    printf("for %x and %d is %x\n",0xffffffff, 3, xbyte(0xffffffff, 3));
    printf("----------- Solution of 2.71 end ---------------\n");

}
//2.71 end
//2.72 start
//A:sizeof返回unsigned，int - unsigned总是返回正数
//B:sizeof挪到右边
//2.72 end
//2.73 start
// 补码运算，使用INT_MAX和MIN作为上下界
int saturating_add(int x, int y)
{
    int sum = x + y;
    int sign = 1<<31;
    // 加数大于0，和小于0，加数小于0，和大于0是溢出
    int overflow = (!(x&sign)) && (!(y&sign)) &&(sum&sign);
    int downflow = (x&sign) && (y&sign) &&(!(sum&sign));
    (overflow && (sum = INT_MAX)) || (downflow && (sum = INT_MIN));
    return sum;
}
void ex_2_73()
{
    printf("----------- Solution of 2.73 start ---------------\n");
    printf("for %x, %x, is %x\n", INT_MAX, INT_MAX, saturating_add(INT_MAX, INT_MAX));
    printf("for %x, %x, is %x\n", -1, INT_MIN, saturating_add(-1, INT_MIN));
    printf("for %x, %x, is %x\n", -1, 3, saturating_add(-1, 3));
    printf("----------- Solution of 2.73 end ---------------\n");
}
//2.73 end
//2.74 start
int tsub_ok(int x, int y)
{
    int minus = x - y;
    // 加数大于0，和小于0，加数小于0，和大于0是溢出
    // y如果是INT_MIN，肯定溢出
    int overflow = (x > 0) && (y<0) && (minus<0);
    int downflow = (x < 0) && (y>0) && (minus>0);
    return !(overflow || downflow || y == INT_MIN);
}
void ex_2_74()
{
    printf("----------- Solution of 2.74 start ---------------\n");
    printf("for %x,%x is %x\n", INT_MAX, INT_MIN, tsub_ok(INT_MAX, INT_MIN));
    printf("for %x,%x is %x\n", INT_MAX, 1111, tsub_ok(INT_MAX, 1111));
    printf("----------- Solution of 2.74 end ---------------\n");
}
//2.74 end
//2.75 start
//**** 参见2.12
int signed_high_prod(int x, int y) {
    int64_t mul = (int64_t) x * y;
    return mul >> 32;
}
unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    int sig_x = x >> 31;
    int sig_y = y >> 31;
    int signed_prod = signed_high_prod(x, y);
    return signed_prod + x * sig_y + y * sig_x;
}
void ex_2_75()
{
    printf("----------- Solution of 2.75 start ---------------\n");
    printf("for %x %x is %x\n", 0xffffffff,2,unsigned_high_prod(0xffffffff,2));
    printf("for %x %x is %x\n", 0xffffffff,8,unsigned_high_prod(0xffffffff,8));
    printf("----------- Solution of 2.75 end ---------------\n");
}
//2.75 end
//2.76 end
void *calloc(size_t nmemb, size_t size)
{
    // 核心是判断乘法是否溢出（结果除以除数）
    // if (nmemb == 0 || size == 0) {
    //     return NULL;
    // }
    // size_t buf_size = nmemb * size;
    // if (nmemb == buf_size / size) {
    //     void* ptr = malloc(buf_size);
    //     if(ptr != NULL) {
    //         memset(ptr, 0, buf_size);
    //     }
    //     return ptr;
    // }
    // return NULL;
}
//2.76 end
//2.77 start
int mult_17(int x)
{
    return (x<<4) + x;
}
int mult_minus_7(int x)
{
    return x - (x<<3);
}
int mult_60(int x)
{
    return (x<<6) - (x<<2);
}
int mult_minus_112(int x)
{
    return (x<<4) - (x<<7);
}
void ex_2_77()
{
    printf("----------- Solution of 2.77 start ---------------\n");
    assert(mult_17(2)==34);
    assert(mult_minus_7(2)==-14);
    assert(mult_60(4)==240);
    assert(mult_minus_112(2)==-224);
    printf("----------- Solution of 2.77 end ---------------\n");
}
//2.77 end
//2.78 start
int divide_power2(int x, int k)
{
    int is_neg = x & (1<<31);
    (is_neg && (x = x + (1 << k) - 1));
    return x >> k;
}
void ex_2_78()
{
    printf("----------- Solution of 2.78 start ---------------\n");
    printf("for %x , %d, result is %x\n", 0xff,2,divide_power2(0xff,2));
    printf("for %x , %d, result is %x\n", -1,2,divide_power2(-1,2));
    printf("----------- Solution of 2.78 end ---------------\n");
}
//2.78 end
//2.79 start****
int mul3div4(int x)
{
    return divide_power2(x + (x<<1), 2);// 这道题的核心是正确舍入：正负数都要向0舍入
}
void ex_2_79()
{
    printf("----------- Solution of 2.79 start ---------------\n");
    printf("for %d is %d \n", 12, mul3div4(12));
    printf("for %d is %d \n", -13, mul3div4(-13));
    printf("for %d is %d \n", INT_MAX - 1 , mul3div4(INT_MAX - 1));
    printf("----------- Solution of 2.79 end ---------------\n");
}
//2.79 end
//2.80 start
int threefourths(int x)
{
    // 错误的答案：负数处理错误！！！
    // return (x >> 1) + (x >> 2);
    // 步骤1：判断x是否为负数（is_neg非0则为负数）
    // INT_MIN的二进制是最高位1，其余0，x&INT_MIN：负数结果为INT_MIN（非0），正数为0
    int is_neg = x & INT_MIN;
    // 步骤2：拆分x为两部分：f（能被4整除的高位） + l（余数低位，0-3）
    // ~0x3 = ...11111100，x&~0x3 会保留x中4的倍数部分，比如x=7→4，x=-7→-8
    int f = x & ~0x3;
    // 0x3=11，x&0x3 提取x除以4的余数（0/1/2/3），比如x=7→3，x=-7→1（因为-7的二进制补码末两位是01）
    int l = x & 0x3;
    // 步骤3：计算能被4整除部分的3/4：3f/4 = f/4 *3
    int fd4 = f >> 2;          // f/4（右移2位等价于除以4，f是4的倍数，无精度丢失）
    int fd4m3 = (fd4 << 1) + fd4;  // fd4*3（左移1位是*2，加自身就是*3）
    // 步骤4：计算余数部分的3倍：3l（l是0-3，3l是0/3/6/9）
    int lm3 = (l << 1) + l;    // l*3，等价于lm3 = 3*l
    // 步骤5：定义偏移量：bias=3（二进制11），用于修正负数余数的舍入
    int bias = (1 << 2) - 1;   // 4-1=3，右移2位的偏移量
    // 步骤6：如果x是负数，给3l加bias（3），修正舍入方向（向零取整）
    // is_neg非0时执行lm3 += bias；正数则不执行
    (is_neg && (lm3 += bias));
    // 步骤7：计算余数部分的3/4：3l/4（加bias后右移2位，实现向零取整）
    int lm3d4 = lm3 >> 2;
    // 步骤8：两部分结果相加，得到最终3x/4
    return fd4m3 + lm3d4;
}
void ex_2_80()
{
    printf("----------- Solution of 2.80 start ---------------\n");
    printf("for %d is %d \n", 12, threefourths(12));
    printf("for %d is %d \n", -13, threefourths(-13));
    printf("----------- Solution of 2.80 end ---------------\n");
}
//2.80 end
//2.81 start
int solution_2_81_a(int j, int k)
{
    return 0xffffffff << k;
}
int solution_2_81_b(int j, int k)
{
    return (0xffffffffu >> (32 -k - j)) & (0xffffffff << j);
}
void ex_2_81()
{
    printf("----------- Solution of 2.82 start ---------------\n");
    printf("for %d and % d is %b \n", 12, 12, solution_2_81_a(12,12));
    printf("for %d and % d is %b \n", 12, 12, solution_2_81_b(12,12));
    printf("----------- Solution of 2.82 end ---------------\n");
}
//2.81 end

//2.82 start
//A:0,x为INT_MIN
//B:1
//C:1
//D:0!!! 1 *********************
//E:1
//2.82 end

//2.83 start
//A:Y/(2^k -1)
//B:a:5/7,b:2/5,c:19/63
//2.83 end

//2.84 start
// (sx > sy) || ((!sx&&!sy) && ux <= uy) || ((sx&&sy) && ux>=uy)
//2.84 end

//2.85 start
// bias = 2^(k-1) - 1
// V = 2^E * M
//A: E:2  M:0b1.11  f:0b0.11   V:7.0
//B: 0b1.1111..... E:bias+n  M:0b1.11....  f:0b0.11....   V:2^(n+1)-1
//C: tmd,翻译错误，这里应该是最小的正规格化数
//2.85 end

//2.86 start
// A:2^(2-2^14-63)
// B:2^(2-2^14)
// C:(2-2^(-63))*2^(2^14-1)
//2.86 end

//2.87 start
//略
//2.87 end

//2.88 start
//略
//2.88 end

//2.89 start
//A:1
//B:0,当y是INT_MIN
//C:0
//D:0
//E:0
//2.89 end

//2.90 start
float u2f(unsigned x)
{
    // return (float) x;
    return *(float*) &x;
}

float fpwr2(int x)
{
    unsigned exp, frac;
    unsigned u;
    if (x < -149) {
        /* Too small. Return 0.0 */
        exp = 0;
        frac = 0;
    } else if (x < -126) {
        /* Denormalized result */
        exp = 0;
        frac = 1 << (unsigned)(x - (2-128-23));
    } else if (x < 128) {
        /* Normalized result. */
        exp = x + 127;
        frac = 0;
    } else {
        /* Too big. Return +oo */
        exp = 0xff;
        frac = 0;
    }
    /* Pack exp and frac into 32 bits */
    u = exp << 23 | frac;
    /* Return as float */
    return u2f(u);
}
void ex_2_90()
{
    printf("----------- Solution of 2.90 start ---------------\n");
    printf("for %d is %b \n", 12, fpwr2(12));// 打印错误
    printf("for %d is %b \n", -12, fpwr2(-12));
    printf("----------- Solution of 2.90 end ---------------\n");
}
//2.90 end

//2.91 start
//A:3.1415927410125732
//B:0b11.001001001001001001001001....
//C:9
//2.91 end

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
    ex_2_66();
    ex_2_67();
    ex_2_68();
    ex_2_69();
    ex_2_70();
    ex_2_71();
    ex_2_73();
    ex_2_74();
    ex_2_75();
    ex_2_77();
    ex_2_78();
    ex_2_79();
    ex_2_80();
    ex_2_81();
    ex_2_90();
}