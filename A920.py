t = input()
while(t>0):
    t-=1


    n,k = map(int,raw_input().split())
    l = map(int,raw_input().split())
    main = [999999999]*n
    for i in range(n):
        for j in range(n):
            if j+1 in l:
                main[i] = min(main[i],abs(j-i))

    print max(main)+1
