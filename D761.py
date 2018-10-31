n,l,r = map(int,raw_input().split(' '))
a = map(int,raw_input().split(' '))
p = map(int,raw_input().split())
l1 =[]
for i in range(n):
    l1.append([p[i],a[i],i])
l1.sort()
# print l1
# d=[]
b=[0]*n
cur = r-l1[n-1][1]
b[l1[n-1][2]]=r
# d.append(r)
curele = r

for i in range(n-2,-1,-1):
    if curele-l1[i][1]>=cur:
        curele = cur-1+l1[i][1]
    b[l1[i][2]] = curele
    cur = curele-l1[i][1]
done =0
for i in b:
    if i<l or i>r:
        done =1
        break
if done==0:
    for i in b:
        print i,
else:
    print -1
