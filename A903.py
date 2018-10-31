t =  input()
while(t>0):
    t-=1
    x = input()
    done = 0
    for i in range(1000):
        a = i
        b = (x - 3*a)/7
        if a*3+b*7 == x and b>=0:
            done = 1
            # print a,b
            print "YES"
            break

    if done==0:
        print "NO"
