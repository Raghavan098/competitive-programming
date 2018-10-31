def gcd(x,y):
    if x>y:
        x,y = y,x
    # print x,y
    if x==0:
        return y
    if y==1:
        return 1
    else:
        return gcd(y%x,x)
def lcm(x,y):
    return x*y/gcd(x,y)

n,k = map(int,raw_input().split())
if k==1:
    print "Yes"
elif(k>=n):
    if n==1 and k==2:
        print "Yes"
    else:
        print "No"
else:
    curr = 2
    currlcm = 2
    p = 3
    while(p-1<=k):
        # print currlcm,p,(n+1)%currlcm,curr
        if((n+1)%currlcm!=0):
            print "No"
            exit(0)
        else:
            currlcm = lcm(currlcm,p)
            curr*=(p)
            if p-1==k:
                break
            p+=1
        # print currlcm,p,(n+1)%currlcm,curr,"asd"

    print "Yes"
