for _ in range(input()):
    n = input()
    a=2**32
    l=[0]*n
    s = 0
    k = 2**32/n
    for i in range(n-1):
        l[i] = k
    s = sum(l)
    if (a -s)%2!=0:
        l[n-2]-=1
        s-=1
    l[n-1] = (a - s)/2

    if(min(l)==l[n-1]):
        l[1]+=l[0]-1
        l[0] = 1
    for i in l:
        print i,
