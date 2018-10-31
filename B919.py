def sumOfDigits(n):
    surr  =0
    while(n>0):
        surr+=n%10
        n/=10
    # print surr
    return surr


n = input()
if n<=9:
    l = [19,28,37,46,55,64,73,82,91]
    print l[n-1]
else:
    temp = n/9
    if n%9==0:
        temp-=1
        temp*=100
        req = 10
        req-=sumOfDigits(temp)
        print temp+(req)*10
    else:
        temp*=100
        req = 10
        req-=sumOfDigits(temp)
        print temp,req
        l = []
        curr = req
        for i in range(req%9):
            l.append(temp+curr)
            curr+=9
        # print l
        print l[req%9-1]
