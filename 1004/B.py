n,m = map(int,raw_input().split())
ans = "10"*(n/2)
if(n%2==1):
    ans += "1"

print ans
