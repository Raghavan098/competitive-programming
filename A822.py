def fact(a):
    ans  = 1
    while(a>0):
        ans*=a
        a-=1
    return ans
a,b = map(int,raw_input().split())
print fact(min(a,b))
