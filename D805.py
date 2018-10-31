def fast_expo(x,y):
    res = 1
    while(y!=0):
        if y&1==1:
            res = (res*x)%(1000000007)
        y = y>>1
        x= (x*x)%(1000000007)
    return res
s = raw_input()
st = 0
n = len(s)
for i in xrange(n):
    if s[i]!='b':
        st = i
        break

acount  = 0
i = st
ans = 0
while i<n:
    if s[i]=='a':
        acount+=1
    else:
        bcount = 0
        while i<n:
            if s[i]=='b':
                i+=1
                bcount+=1
            else:
                i-=1
                break

        ans+=((fast_expo(2,acount)-1)*bcount)

        # print 1*(2**acount-1)*bcount,
    # print i
    # print ans
    i+=1

print ans%(10**9+7)
