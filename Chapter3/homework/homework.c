//
// Created by root on 2026/3/27.
//
// 3.58
long decode2(long x, long y, long z)
{
    // long tmp = y - z;
    // return (tmp * x) ^ (tmp << 63 >> 63);
    y = y - z;
    x = y * x;
    long val = y;
    val = val << 63;
    val = val >> 63;
    val = val ^ x;
    return val;
}

// 3.59
//无符号乘法的高64位加上符号修正
//理解了符号修正，就很容易理解这段汇编

//3.60
long loop(long x , int n)
{
    long result = 0;
    long mask;
    for (mask = 1; mask != 0; mask <<=  n)
    {
        result |= (x & mask);
    }
    return result;
}

//3.61
long cread(long *xp)
{
    return (xp ? *xp : 0);
}

long cread_alt(long *xp)
{
    return (!xp ? 0 : *xp);
}
// 备注，在新版gcc中，这两个函数被编译成一样的结果！！！！


// 3.62
typedef enum {MODE_A, MODE_B, MODE_C, MODE_D, MODE_E} mode_t;

long switch3(long *p1, long *p2 ,mode_t action)
{
    long result = 0;
    switch (action)
    {
        case MODE_A:
            result = *p2;
            long tmp = *p1;
            *p2 = tmp;
            break;
        case MODE_B:
            result = *p2;
            result += *p1;
            *p1 = result;
            break;
        case MODE_C:
            *p1 = 59;
            result += *p2;
            return result;
        case MODE_D:
            result = *p2;
            *p1 = result;
            result = 27;
            return result;
        case MODE_E:
            result = 27;
            return result;
        default:
            result = 12;
            return result;
    }
    return result;
}











