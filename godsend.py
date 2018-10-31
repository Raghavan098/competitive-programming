n = input()
l = map(int,raw_input().split(' '))
l1 = sum(l)
if l1%2 == 1:
    print "First"
else:
    k = 0
    done = 0
    for i in l:
        k+=i
        if k%2 ==1:
            done =1
            print "First"
            break
    if done == 0:
        print "Second"
