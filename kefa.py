import math
n,k = map(int,raw_input().split(' '))
s= raw_input()
d={}
for i in s:
    if i not in d:
        d[i]=1
    else:
        d[i]+=1
q=0
for i in d:
    if d[i]>k:
        q = 1
        print "NO"
        break
if q == 0:
    print "YES"
