def check(n,k):
    if k==0:
        return 0
    dp = [0]*(n+1)
    dp[0]=1
    cur = 0
    sub = 0
    su = 1
    # print dp[0]
    for i in range(1,n+1):
        dp[i] = su
        su+=dp[i]
        if i >= k:
            sub=dp[cur]
            cur+=1
            su-=sub
        # print dp[i],i,su
    return dp[n]

n,k,d = map(int,raw_input().split(' '))
print (check(n,k)-check(n,d-1))%1000000007
