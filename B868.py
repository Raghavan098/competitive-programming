def check(x,t2,t1):
    if x>t1 and x<t2:
        return 2
    elif x>t1 and x>t2:
        return 1
    elif x<t1 and x<t2:
        return 1
h,m,s,t1,t2 = map(int,raw_input().split(" "))
if m>0 or s>0:
    h= (h*5%60+1)%60
else:
    h = (h*5)%60
if s>0:
    m = (m+0.1)%60
# print h
t1 = (t1*5)%60
t2 = (t2*5)%60
k1 = check(h,max(t1,t2),min(t1,t2))
k2 = check(m,max(t1,t2),min(t1,t2))
k3 = check(s,max(t1,t2),min(t1,t2))
# print k1,k2,k3
if k1==None:
    k1 = max(k2,k3)
if k2==None:
    k2 = max(k1,k3)
if k3==None:
    k3 = max(k1,k2)
if k1==None and k2==None and k3==None:
    k1 = 1
    k2 = 1
    k3 = 1
if k1==k2 and k2==k3:
    print "YES"
else:
    print "NO"
