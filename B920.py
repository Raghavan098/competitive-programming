t = input()
while t>0:
    t-=1
    n = input()
    k = []
    for i in range(n):
        k1 = map(int,raw_input().split())
        k.append([k1[0],i,k1[1],-1])

    # k.sort()
    for i in range(2005):
        done = 0
        for j in range(n):
            if k[j][3]==-1 and i+1>=k[j][0]:
                k[j][3] = i+1
                done = 1
                for i1 in range(j+1,n):
                    k[i1][2]-=1
                    if k[i1][2]<=0:
                        k[i1][3] = 0
            else:
                for i in range(j+1,n):
                    k[i1][2]-=1
                    if k[i1][2]<=0:
                        k[i1][3] = 0
            if done==1:
                break
        # for m in k:
        #     print m
    for i in k:
        print i[3],

    print ""
