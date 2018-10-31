t = input()
while t>0:
    t-=1
    n = input()
    l = map(int,raw_input().split())
    if n==1:
        print 1
        continue
    l1 = 0
    l2 = 0
    for i in l:
        if i%2==1:
            l1+=1
        else:
            l2+=1
    if l1==0:
        print 1
    elif l2==0:
        if l1%2==1:
            print 2
        else:
            print 1
    else:
        if l1%2==1:
            print 2
        else:
            print 1
