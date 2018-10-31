a,b,f,k=map(int,raw_input().split(' '))
c=0
p=b-f
z=0
if p<0:
    z=-1
for i in range(k-1):
    if(i%2==0):
       if p<2*(a-f):
           c+=1
           p=b
       p=p-2*(a-f)
    else:
        if p<2*f:
            c+=1
            p=b
        p=p-2*f
    if p<0:
        z=-1
if k%2==0:
    if p<f:
        p=b
        c+=1
    p-=f
else:
    if p<(a-f):
        p=b
        c+=1
    p-=a-f
if p<0:
    z=-1
if z==-1:
    print z
else:
    print c
