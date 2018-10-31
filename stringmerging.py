def lcs(x,y,n,m):
    m = len(x)
    n = len(y)
    l = [[None]*(n+1) for i in range(m+1)]
    for i in xrange(m+1):
        for j in range(n+1):
            if i==0 or j==0:
                l[i][j]=0
            elif x[i-1]==y[j-1]:
                l[i][j] = l[i-1][j-1]+1
            else:
                l[i][j] = max(l[i-1][j],l[i][j-1])
    return l[m][n]
t = input()
while(t>0):
    t-=1
    n,m = map(int,raw_input().split())
    a = raw_input()
    b = raw_input()
    aa = a[0]
    curr = aa
    for i in range(1,n):
        if a[i]!=curr:
            curr = a[i]
            aa+=curr
    bb = b[0]
    curr = bb
    for i in range(1,m):
        if b[i]!=curr:
            curr = b[i]
            bb+=curr
    k = lcs(aa,bb,len(aa),len(bb))
    ans = len(aa)+len(bb)-k
    print ans
