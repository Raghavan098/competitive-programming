l = map(int,raw_input().split())
x = max(l)
yes = 0
for i in range(2*x+1):
    for j in range(2*x+1):
        for k in range(2*x+1):
            if i>=l[0] and 2*l[0]>=i and j>=l[1] and 2*l[1]>=j and k>=l[2] and 2*l[2]>=k and k>=l[3] and 2*l[3]>=k and 2*l[3]<i and 2*l[3]<j:
                print i
                print j
                print k
                yes = 1
                break
        if yes==1:
            break
    if yes==1:
        break
if yes==0:
    print -1
