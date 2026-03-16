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