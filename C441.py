n,m,k = map(int,raw_input().split(' '))
curn =1
curm =1
state =0
finis = 0
for i in range(k-1):
    print 2,
    for j in range(2):
        print curn,curm,
        finis+=1
        if curm == m and state==0:
            curn+=1
            state=1
        elif curm==1 and state ==1:
            curn+=1
            state=0
        elif state==0:
            curm+=1
        else:
            curm-=1
    print ""
l=[]
while finis!=m*n:
    l.append([curn,curm])
    finis+=1
    if curm == m and state==0:
        curn+=1
        state=1
    elif curm==1 and state ==1:
        curn+=1
        state=0
    elif state==0:
        curm+=1
    else:
        curm-=1
print len(l),
for i in l:
    print i[0],i[1],
