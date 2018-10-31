t = input()
while t>0:
    t-=1
    n = input()
    l = map(int,raw_input().split())
    l.sort()
    count = 0
    for i in range(1,n):
        if l[i]==l[i-1]:
            count+=1

    print count
