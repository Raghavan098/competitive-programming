t = input()
while(t>0):
    t-=1
    d={}
    n = input()
    for i in range(n):
        x = raw_input()
        if x not in d:
            d[x]=1
        else:
            d[x]+=1
    a = 0

    b = 0
    temp =0
    for i in d:
        if temp==0:
            a = d[i]
            a1 = i
            temp =1
        else:
            b = d[i]
            b1 = i
    if a==b:
        print  "Draw"
    elif a>b:
        print a1
    else:
        print b1
