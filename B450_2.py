a,b,c = map(int,raw_input().strip().split(' '))
yes = 0
a = a%b
d = {}
count = 0
k = 0
while(yes==0):
    if a in d:
        yes = 1
    d[a] = 1
    tcc = -1
    while(a<b and a!=0):
        a = a*10
        tcc+=1
    x = a/b
    a = a%b
    count+=1
    tc = 0
    pop = tcc*"0"+str(x)
    for i in pop:
        if i==str(c):
            k = 1
            print count+tc
            yes = 1
            break
        tc+=1
    if tcc!=-1:
        count+=tcc
if k==0:
    print -1
