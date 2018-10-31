n = input()
s = (n*(n+1))/2
if s==1:
    print 1
    print 1,1
elif s%2 ==0:
    print 0
    s = s/2
    k = 0
    p = []
    for i in range(n,-1,-1):
        if k+i<s:
            p.append(i)
            k = k+i
        else:
            break
    p.append(s-k)
    print len(p),
    for i in p:
        print i,

else:
    print 1
    s = s/2
    k = 0
    p = []
    for i in range(n,-1,-1):
        if k+i<s:
            p.append(i)
            k = k+i
        else:
            break
    p.append(s-k)
    print len(p),
    for i in p:
        print i,
