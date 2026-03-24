//
// Created by root on 2026/3/10.
//
// practice
void decode1(long *xp, long *yp, long *zp)
{
    long x = *xp;
    long y = *yp;
    long z = *zp;
    *yp = x;
    *zp = y;
    *xp = z;
}

long scale(long x, long y, long z)
{
    long t = x + 4*y + 12*z;
    return t;
}

long arith2(long x ,long y, long z)
{
    long t1 = x | y;
    long t2 = !(t1 >> 3);
    long t3 = z;
    long t4 = z - t2;
    return t4;
}

void cond(long a, long * p)
{
    if (p ==0)
    {
        goto L1;
    }
    if (*p >= a)
    {
        goto L1;
    }
    *p = a;
    L1:
        return;
}

long test(long x, long y, long z)
{
    long val = x + y + z;
    if (x < -3)
    {
        if (y < z)
            val = x*y;
        else
            val = y*z;
    } else if (x > 2)
        val = x * z;
    return val;
}

long arith1(long x )
{
    long val = x + 7;
    if (x >= 0)
    {
        val = x;
    }
    val = val >> 3;
    return val;
}

long test1(long x, long y)
{
    long val = 8*x;
    if (y>0)
    {
        if (x>y)
        {
            val = x&y;
        } else
        {
            val = y - x;
        }
    } else if (y<=-2)
    {
        val = x+y;
    }
    return val;
}

long loop_while2(long a, long b)
{
    long result = b;
    while (b <= 0)
    {
        result = result * a;
        b = b - a;
    }
    return result;
}

long fun_a(unsigned long x)
{
    long val = 0;
    while (x != 0)
    {
        val = val^x;
        x = x >> 1;
    }
    return val&1;
}

struct ELE
{
    long v;
    struct ELE *p;
};

long fun (struct ELE *ptr)
{
    long val = 0;
    while (ptr)
    {
        val += ptr->v;
        ptr = ptr->p;
    }
    return val;
}