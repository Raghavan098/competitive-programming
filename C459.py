n,k,d = map(int,raw_input().split())
if n>k**d:
    print -1
else:
    ans = []
    l = 1
    # print k
    for i in xrange(d):
        ki = []
        temp = 0
        w = 1
        if l>n:
            l = n
        for j in xrange(n):
            for t in xrange(l):
                ki.append(j%k+1)
                temp+=1
                if temp==n:
                    w = 0
                    break
            if w==0:
                break
        l*=k
        ans.append(ki)
    for i in ans:
        for j in i:
            print j,
        print ""
