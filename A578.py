import math
a,b = map(int,raw_input().split())
if b>a:
    print -1
elif b==a:
    print b
else:
    x=(a-b)*1.0/2
    k = math.floor(x/b)
    if(k==0):
        ans1 = -1
    else:
        ans1 = (x*1.0)/k

    x = (a+b)*1.0/2
    k = math.floor(x/b)-1
    # print k
    if k<0:
        k+=1
    ans2 = (x*1.0)/(k+1)
    # print ans1,ans2
    if ans1!=-1:
        print min(ans1,ans2)
    else:
        print ans2
