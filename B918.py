n,m = map(int,raw_input().split())
l = []
d = {}
for i in range(n):
    k = raw_input().split()
    d[k[1]] = k[0]

for i in range(m):
    s = raw_input().split()
    ans =""
    for i in s:
        ans+=i
        ans+=" "
    ans+=" "
    ans+="#"
    ans+=d[s[1][:-1]]
    print ans
