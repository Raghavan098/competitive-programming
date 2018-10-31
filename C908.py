import math
n,r = map(int,raw_input().split())
l = map(int,raw_input().split())
ans = [r]
for i in range(1,n):
    m = -1
    for j in range(i):
        if abs(l[i]-l[j])<=2*r:
            # print (2*r)**2 - (l[j]-l[i])**2,i,j
            h = ans[j]+math.sqrt((2*r)**2 - (l[j]-l[i])**2)
        else:
            h = r
        if h>m:
            m = h
    ans.append(m)
for i in ans:
    print i,
