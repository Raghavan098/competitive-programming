import math
n = input()
l = map(int,raw_input().split())
a = []
b = []
for i in l:
    temp = int(math.sqrt(i))
    if temp*temp == i:
        a.append(i)
    else:
        q = min(i-temp*temp,(temp+1)*(temp+1)-i)
        b.append([q,i])
# print a
# print b
if len(a)==len(b):
    print 0
elif len(a)>len(b):
    x = len(a)
    y = len(b)
    a.sort()
    a.reverse()
    count=0
    for i in a:
        if x!=y:
            if i==0:
                count+=2
            else:
                count+=1
            x-=1
            y+=1
    print count
else:
    x = len(a)
    y = len(b)
    b.sort()
    count = 0
    for i in b:
        if x!=y:
            count+=i[0]
            x+=1
            y-=1
    print count
