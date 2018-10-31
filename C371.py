s = raw_input()
nb,ns,nc = map(int,raw_input().split())
pb,ps,pc = map(int,raw_input().split())
x = input()
a1,a2,a3 = 0,0,0
for i in s:
    if i=='B':
        a1+=1
    elif i=='S':
        a2+=1
    else:
        a3+=1
try:
    f = nb/a1
except:
    nb = 0
    f = 1001
try:
    g = ns/a2
except:
    ns = 0
    g = 1001
try:
    h = nc/a3
except:
    nc = 0
    h = 1001
done = min(f,g,h)
# print done
nb-=done*a1
ns-=done*a2
nc-=done*a3
no=0
while(nb>0 or ns>0 or nc>0):
    # print nb,ns,nc,x
    no=0
    while nb<a1:
        if x>=pb:
            nb+=1
            x-=pb
        else:
            no=1
            break
    if no==1:
        break
    while ns<a2:
        if x>=ps:
            ns+=1
            x-=ps
        else:
            no=1
            break
    if no==1:
        break
    while nc<a3:
        if x>=pc:
            nc+=1
            x-=pc
        else:
            no=1
            break
    if no==1:
        break
    else:
        nb-=a1
        ns-=a2
        nc-=a3
        done+=1
# print nb,ns,nc,x
# print done
done+=(x/(a1*pb+a2*ps+a3*pc))
print done
