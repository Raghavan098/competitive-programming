import math
def toString(x):
    ans =""
    while(x):
        if x%2==0:
            ans+="0"
        else:
            ans+="1"
        x/=2
    ans+="0"
    return ans[::-1]
n = input()
count = 0
for i in range(1,2**int(math.ceil(math.log(n)))+1):
    s = toString(i)
    if n>= int(s):
        count+=1
    else:
        break

print count
