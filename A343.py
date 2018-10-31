def solve(a,b):
    # print a,b
    if a==1:
        return b
    if(a>b and a%b==0):
        return a/b
    if(a>b):
        return a/b+solve(a%b,b)
    else:
        return b/a+solve(a,b%a)
n,m = map(int,raw_input().split())
print solve(n,m)
