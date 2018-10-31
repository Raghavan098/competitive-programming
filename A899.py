n = input()
l = map(int,raw_input().split())
d = {}
d[2] = 0
d[1] = 0
for i in l:
    d[i]+=1
count = 0
x= min(d[2],d[1])
count+=x
d[2]-=x
d[1]-=x
if d[1]>0:
    count+=d[1]/3
print count
