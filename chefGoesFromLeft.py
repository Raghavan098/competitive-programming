t = input()
while(t>0):
    n,k = map(int ,raw_input().split(' '))
    l = map(int,raw_input().split(' '))
    if n==1:
        print "YES"

    if n==2:
        print "YES"
    if n>2:
        done =0
        if l[0]<k:
            mx = 1000000004
            mi = l[0]
        else:
            mx = l[0]
            mi = -1
        for i in range(len(l)):
            if l[i]>mx or l[i]<mi:
                done =1
                print "NO"
                break
            if l[i]<mx and l[i]>k:
                mx = l[i]
            if l[i]>mi and l[i]<k:
                mi = l[i]
        if done==0:
            print "YES"
    t-=1
