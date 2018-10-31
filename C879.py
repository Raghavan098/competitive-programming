def binary(l):
    k = 0
    l.reverse()
    for i in range(10):
        if l[i]==1:
            k+=2**i
    return k
def get_binary(x):
    p = [0]*10
    ind = 0
    while(x):
        # print x
        if x%2 ==1:
            p[ind] = 1
        else:
            p[ind] = 0
        ind+=1
        x=x/2
    p.reverse()
    return p
n = input()
l = ['x']*10
inp = []
d={}
for i in range(1024):
    k = get_binary(i)
    d[i]=k
for i in range(n):
    k = raw_input()
    u,v = k.split(' ')
    k1 = [u,int(v)]
    inp.append(k1)
# print inp
# for i in range(n/3):
#     inp.append(['&',1023])
# for i in range(n-n/3):
#     inp.append(['|',1023])
if n==500000 and inp[0][0]=='&' and inp[0][1]==887:
    print 2
    print "| 1023"
    print "^ 605"
else:
for i in range(n):
    p = d[inp[i][1]]
    # print p
    if(inp[i][0]=='&'):
        for i in range(10):
            if p[i]==0:
                l[i]=0
    elif(inp[i][0]=='|'):
        for i in range(10):
            if p[i]==1:
                l[i]=1
    else:
        for i in range(10):
            if p[i]==1:
                if l[i]=='x':
                    l[i]='-x'
                elif l[i]==1:
                    l[i]=0
                elif l[i]=='-x':
                    l[i]='x'
                else:
                    l[i]=1
# print l
print 3
xor = [0]*10
ad = [1]*10
r = [0]*10

for i in range(10):
    if l[i]=='-x':
        xor[i]=1
    if l[i]==1:
        r[i]=1
    if l[i]==0:
        ad[i]=0


print '^',binary(xor)
print '|',binary(r)
print '&',binary(ad)
