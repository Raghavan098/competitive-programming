n = input()
l = map(int,raw_input().split())
l.sort()
cs = [0]*n
cs[n-1] = l[n-1]
for i in range(n-2,-1,-1):
    cs[i] = cs[i+1]+l[i]

i=0
j=1
ans = 0
for i in range(n):
    while(j<n and l[j]-l[i]<=1):
        j+=1
    print j,i
    if j<n:
        ans+=(cs[j]-l[i]*(n-j))
        print "ans",ans

print ans
