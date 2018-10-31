t = input()
while(t>0):
    t-=1
    x,n = map(int,raw_input().split())
    s = ((n*(n+1))/2)-x
    # print s
    if s%2==1:
        print "impossible"
    else:
        p = 0
        l1 = []
        s = s/2
        for i in range(n,1,-1):
            if i!=x and s-(p+i)!=x:
                if p+i<=s:
                    p+=i
                    l1.append(i)
        # print l1
        done = 0
        if p<s:
            if s-p!=x:
                l1.append(s-p)
            else:
                print "impossible"
                done = 1

        if done==0:
            ans = [0]*(n+1)
            for i in l1:
                ans[i] = 1

            ans[x] = 2
            strans = ""
            for i in range(1,n+1):
                strans+=str(ans[i])

            print strans
