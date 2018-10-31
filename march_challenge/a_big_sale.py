t = input()
while t>0:
    t-=1
    n = input()
    loss = 0
    for i in range(n):
        l = map(int,raw_input().split())
        k1 = l[0]*0.01*l[2]
        p2 = l[0]+k1
        k2 = p2*0.01*l[2]
        loss+=(l[1]*(k2-k1))

    print loss
