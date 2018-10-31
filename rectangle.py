t = input()
while(t>0):
    t-=1
    l = map(int,raw_input().split())
    l.sort()
    if l[0]==l[1] and l[2]==l[3]:
        print "YES"
    else:
        print "NO"
