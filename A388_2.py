n = input()
l = map(int,raw_input().split(' '))
l.sort()
done =0
for h in range(1,101):
    p=0
    for i in range(n):
        if i/h>l[i]:
            p=1
            break

    if p==0:
        done = 1
        print h
        break
if done == 0:
    print 100
