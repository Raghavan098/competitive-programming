n,k = map(int,raw_input().split())
arr = map(int,raw_input().split())
ans = -1;
for i in range(n):
    s = 0
    for j in range(i,n):
        s += arr[j]
        if ((j-i + 1)) >= k:
            ans = max(ans,s*1.0/(j-i +1))

print ans
