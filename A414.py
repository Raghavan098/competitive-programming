n,g = map(int,raw_input().split())
if g==0 and n==1:
    print 1
elif 2*g+1<n:
    print -1
else:
    l = []
    k=0
    if n%2 == 1:
        k = 1
        n = n-1

    x = g - (n-2)/2
    # print x
    l.append(x)
    l.append(2*x)
    x = 2*x+1
    for i in range(n-2):
        l.append(x+i)

    if k==1:

        l.append(l[n-1]+1)
        n = n+1
    if len(l)==n:
        for i in l:
            print i,
        print ""
    else:
        print -1
