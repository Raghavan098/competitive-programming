import math

t = input()
while(t>0):
    t-=1
    x = input()
    if(x==0):
        print 1,1
        continue

    done = -1
    for i in range(1,100001):
        if i*i>x:
            root =  math.sqrt(i*i - x)
            if int(root)==root and root<=(i/2 +1)and root!=0:
                n = i
                m = int(i/int(root))
                # print n,m
                if n**2 - (n/m)**2 == x:
                    print n,m
                    done = 1

    if done==-1:
        print -1
