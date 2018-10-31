def check(l1,l2):
    for i in range(len(l1)):
        if l2[i]<l1[i]:
            return 0
    return 1

t = input()
while(t>0):
    t-=1
    n = input()
    l1 = map(int,raw_input().split())
    l2 = map(int,raw_input().split())
    k1 = check(l1,l2)
    l2.reverse()
    k2 = check(l1,l2)
    if k1==1 and k2==1:
        print "both"
    elif k1==1:
        print "front"
    elif k2==1:
        print "back"
    else:
        print "none"
