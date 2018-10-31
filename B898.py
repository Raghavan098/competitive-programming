n = input()
a = input()
b = input()
p=0
for x in range(n):
    y = (n - x*a)/b
    if x*a+y*b == n and y>=0:
        p = 1
        print "YES"
        print x,y
        break
if p==0:
    print "NO"
