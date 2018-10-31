n = input()
if n==2:
    print 1,2
else:
    ans = []
    for i in range(n/2+1,n+1):
        ans.append(i)
    for i in range(1,n/2+1):
        ans.append(i)
    for i in ans:
        print i,
