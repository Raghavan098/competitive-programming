def sumOfDigits(n):
    surr  =0
    while(n>0):
        surr+=n%10
        n/=10
    # print surr
    return surr

n = input()
curr = 19
pos = 9
for i in range(n-1):
    curr+=9
    while(sumOfDigits(curr)!=10):
        print curr,pos,i
        curr+=pos
    print curr,i
print curr
