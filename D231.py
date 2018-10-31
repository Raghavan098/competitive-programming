
r=lambda:map(int,raw_input().split())
c2 = r()
c1 = r()
a = r()
s = 0
if c2[1]>c1[1]:
    s+=a[1]
if c2[1]<0:
    s+=a[0]
if c2[0]>c1[0]:
    s+=a[5]
if c2[0]<0:
    s+=a[4]
if c2[2]>c1[2]:
    s+=a[3]
if c2[2]<0:
    s+=a[2]

print s
