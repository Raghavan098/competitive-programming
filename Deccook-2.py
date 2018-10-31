t = input()
while(t>0):
    t-=1
    n = input()
    l = map(int,raw_input().split())
    x = sum(l)
    if x%4!=0:
        print -1
    else:
        d = {}
        d[0] = 0
        d[1] = 0
        d[2] = 0
        d[3] = 0
        for i  in l:
            d[i%4]+=1
        # print d
        ans = 0
        x = min(d[1],d[3])
        ans+=x
        d[1]-=x
        d[3]-=x
        x = d[2]/2
        ans+=x
        d[2]-=(2*x)
        if d[1]>=2 and d[2]>0:
            d[1]-=2
            d[2]-=1
            ans+=2
        if d[3]>=2 and d[2]>0:
            d[3]-=2
            d[2]-=1
            ans+=2
        if d[1]>0:
            ans+=(d[1]/4)*3
        if d[3]>0:
            ans+=(d[3]/4)*3
        # print d
        print ans
