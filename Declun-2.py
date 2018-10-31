def get(n):
    return (n - 9*((n-1)/9))
def fast_expo(x,y):
    res = 1
    while(y!=0):
        if y&1==1:
            res = res*x
            res = get(res)
        y = y>>1
        x= x*x
        x = get(x)
    return res
t = input()
for _ in xrange(t):
    a,n= map(int,raw_input().split())
    a = get(a)
    print fast_expo(a,n)
