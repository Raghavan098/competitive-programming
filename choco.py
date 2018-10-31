
import math
d={}
def get(i):
    global d
    if i in d:
        return d[i]
    else:
        if i%2==0:
            return 2
        else:
            for j in range(3,i+1):
                if i%j == 0:
                    d[i] = j
                    return j
def solve(t):
    ans = t
    pie = t
    while(pie!=1):
        u = get(pie)
        pie/=u
        ans+=pie
    return ans
        # return x*solve(t/x)
temp = input()
l = map(int,raw_input().split())
fin  = 0
for i in l:
    t = i
    ans = solve(t)
    print ans
    fin+=ans
print fin
