for _ in range(input()):
    n,k = map(int,raw_input().strip().split(' '))
    l = map(int,raw_input().strip().split(' '))
    l.sort()
    cur =0
    done =0
    for i in l:
        if i>cur:
            k-=(i-cur)
        # print i,k,cur
        if k<0:
            done =1
            k+=(i-cur)

            print cur+k
            break
        cur=i+1
    if done==0:
        print l[n-1]+1+k
