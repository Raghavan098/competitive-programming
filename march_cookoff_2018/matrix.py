#fuck you python
t = input()
while(t>0):
    t-=1
    n,m = map(int,raw_input().split())
    inp = []
    ans = []
    for i in range(n):
        l = map(int,raw_input().split())
        temp = [0]*m
        inp.append(l)
        ans.append(temp)



    if inp[0][0]==-1:
        inp[0][0] = 1
        ans[0][0] = 1
    else:
        ans[0][0] = inp[0][0]
    for i in range(1,m):
        if inp[0][i]==-1:
            ans[0][i] = inp[0][i-1]
        else:
            ans[0][i] = inp[0][i]

    for i in range(1,n):
        for j in range(m):
            if inp[i][j]==-1 and j>0:
                lw = max(ans[i-1][j],ans[i][j-1])
                ans[i][j] = lw
            elif inp[i][j]==-1 and j==0:
                ans[i][j] = ans[i-1][j]
            else:
                ans[i][j] = inp[i][j]
    done = 0
    # for i in range(n):
    #     for j in range(m):
    #         print ans[i][j],
    #     print ""

    for i in range(n):
        for j in range(1,m):
            if ans[i][j]<ans[i][j-1]:
                done = 1
                break

        if done == 1:
            break




    for i in range(m):
        for j in range(1,n):
            if ans[j][i]<ans[j-1][i]:
                done = 1
                break
        if done  == 1:
            break
    if done == 0:
        for i in range(n):
            for j in range(m):
                print ans[i][j],
            print ""
    else:
        print -1
