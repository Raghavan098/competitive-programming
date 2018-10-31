n,k = map(int,raw_input().split())
l = map(int,raw_input().split())
l.sort()
mxc = 1
ans = l[0]
co = 1
j = 0
for i in range(1,n):
    k-=(l[i]-l[i-1])*co
    co+=1
    while(k<0):
        k+=l[i]-l[j]
        co-=1
        j+=1
    if co>mxc:
        mxc = co
        ans = l[i]

print mxc,ans
