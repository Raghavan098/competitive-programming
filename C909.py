n = input()
l = []
for i in range(n):
    l.append(raw_input())
i = 0
while(i<n and l[i]=='s'):
    i+=1
bl = 0
while(i<n):
    bl+=1
    i+=1
    while(i<n and l[i]=='f'):
        i+=1
    while(i<n and l[i]=='s'):
        i+=1
# bl=2500
if bl==0:
    print 1
else:
    if bl==2:
        print 2
    elif bl==1:
        print 1
    else:
        # print bl
        x = [0]*(bl+4)
        x[0] = 1
        p = 2
        while(p<bl):
            p+=1
            temp = sum(x)
            temp2 = sum(x)
            y = 0
            uarr = []
            for i in x:
                uarr.append(i)
            for i in range(2,p-1):
                x[i] = temp2-uarr[y]
                temp2-=uarr[y]
                y+=1
            x[0] = temp
            x[1] = temp
        s = 0
        cur = 2
        for i in x:
            s+=(cur*i)%(10**9+7)
            cur+=1
        print s
