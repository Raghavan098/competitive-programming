import math

n = input()
l = map(int,raw_input().split())
s = sum(l)

c = 0
for i in range(len(l)):
    c+=l[i]
    if c>=math.ceil(s/2):
        print i+1
        break
