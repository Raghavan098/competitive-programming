for _ in range(input()):
    a = raw_input()
    d = {}
    for i in a:
         if i not in d:
             d[i]=1
    n,m = map(int,raw_input().split(" "))
    l = []

    for i in range(n):
        k = 0
        d2 ={}
        s = raw_input()
        for j in s:
            if j in d and j not in d2:
                k+=1
                d2[j]=1
        if k>=m:
            l.append(s)
    if l!=[]:
        print ("Yes")
        for i in l:
            print (i)
    else:
        print ("No")
