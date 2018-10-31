n,m = map(int,raw_input().split())
l = map(int,raw_input().split())
l.sort()
ans = -1
for i in range(n-1,-1,-1):
    if m%l[i]==0:
        ans  = m/l[i]
        break
print ans
