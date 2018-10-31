import math
n  = input()
l = map(int,raw_input().split())
m = -1000006
for i in l:
    if i>0 and (i*1.0)**0.5 != int((i*1.0)**0.5) and i>m:
        m = i
    elif i<0 and i>m:
        m =i
print m
