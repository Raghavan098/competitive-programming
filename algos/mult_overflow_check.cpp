// ans of ans*x is stored in temp
if (__builtin_umull_overflow(ans, x, temp))
{
    return false;
    // returned non-zero: there has been an overflow
}
else
{
    ans = ans * x;
    // return zero: there hasn't been an overflow
}
