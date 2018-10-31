n,d = map(int,raw_input().split())
l = map(int,raw_input().split())
m = input()
l.sort()

if m<=n:
    s = 0
    for i in range(m):
        s+=l[i]
    print s
else:
    s = sum(l)
    for i in range(m-n):
        s -= d
    print s
