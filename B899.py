def check(x,y):
    # print x
    # print y
    for i in range(len(y)-len(x)+1):
        p = 0
        for j in range(len(x)):
            if x[j]!=y[i+j]:
                p = 1
                break
        if p==0:
            return True
    return False
n = input()
l = map(int,raw_input().split())
leapandnormalandnormal = [31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31]
normalandleapandnormal = [31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31]
normalandnormalandleap = [31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31]
normalandnormalandnormal = [31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31]
# normalandleap = [31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31]
# normalandnormal = [31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31]
x = check(l,leapandnormalandnormal)
y = check(l,normalandleapandnormal)
z = check(l,normalandnormalandleap)
k = check(l,normalandnormalandnormal)
if(x==True or y==True or z==True or k==True):
    print "YES"
else:
    print "NO"
