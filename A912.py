n,m = map(int,raw_input().split())
l = map(int,raw_input().split())
reqn = l[0]*2
reqn+=l[1]
reqb = l[1]
reqb+= l[2]*3
ans =0
if reqn-n>0:
    ans+=(reqn-n)
if reqb-m>0:
    ans+=(reqb-m)
if ans<0:
    print 0
else:
    print ans
