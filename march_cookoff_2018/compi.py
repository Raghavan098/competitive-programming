t = input()
while(t>0):
    t-=1
    n = input()
    a = map(int,raw_input().split())
    b = map(int,raw_input().split())
    a.sort()
    b.sort()
    a1 = sum(a[0:n-1])
    b1 = sum(b[0:n-1])
    if a1>b1:
        print "Bob"
    elif b1>a1:
        print "Alice"
    else:
        print "Draw"
