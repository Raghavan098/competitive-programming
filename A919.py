n,m = map(int,raw_input().split())
l1 = []
for i in range(n):
    l = map(int,raw_input().split())
    l1.append(l[0]*1.0/l[1])

l1.sort()
print l1[0]*m
