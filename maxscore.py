t = input()
while(t>0):
    t-=1
    n= input()
    l = []
    for i in range(n):
        k = map(int,raw_input().split())
        k.sort()
        l.append(k)
    l.reverse()
    s = 0
    s+=l[0][n-1]
    curr = l[0][n-1]
    done = 0
    for i in range(1,n):
        yes = 0
        for j in range(n-1,-1,-1):
            if l[i][j]<curr:
                curr = l[i][j]
                s+=curr
                yes = 1
                break
        if yes==0:
            done = 1
            break
    if done==0:
        print s
    else:
        print -1
