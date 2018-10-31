t = input()
while(t>0):
    t-=1
    n,k = map(int,raw_input().split())
    l = map(int,raw_input().split())
    prx_sum = [0]*n
    prx_sum[0] = l[0]
    sux_sum = [0]*n
    sux_sum[n-1] = l[n-1]
    for i in range(1,n):
        prx_sum[i] = prx_sum[i-1]+l[i]
    for i in range(n-2,-1,-1):
        sux_sum[i] = sux_sum[i+1]+l[i]
    
