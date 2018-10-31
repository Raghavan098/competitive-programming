def maxSubArraySum(a,size):

    max_so_far =a[0]
    curr_max = a[0]

    for i in range(1,size):
        curr_max = max(a[i], curr_max + a[i])
        max_so_far = max(max_so_far,curr_max)

    return max_so_far
t = input()
while(t>0):
    t-=1
    n,k = map(int,raw_input().split())
    l = map(int,raw_input().split())
    y = maxSubArraySum(l,n)
    if k==1:
        print y
    elif k==2:
        b = []
        for i in range(2*n):
            b.append(l[i%n])
        x = maxSubArraySum(b,2*n)
        print x
    else:
        if sum(l)>=0:
            l.append(sum(l)*(k-2))
            for i in range(n):
                l.append(l[i])
            print maxSubArraySum(l,2*n+1)
        else:
            for i in range(n):
                l.append(l[i])
            print maxSubArraySum(l,2*n)
