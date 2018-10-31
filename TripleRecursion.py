n,m,k = map(int,raw_input().split(' '))
ans = []
for i in range(n):
    p = []
    for j in range(n):
        if i==0 and j==0:
            p.append(m)
        elif i==j:
            p.append(ans[i-1][j-1]+k)
        elif i<j:
            p.append(p[j-1]-1)
        elif i>j:
            p.append(ans[i-1][j]-1)
    ans.append(p)
for i in range(n):
    for j in ans[i]:
        print j,
    print ""
