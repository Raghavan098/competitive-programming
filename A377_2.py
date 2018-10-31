from sys import getrecursionlimit, setrecursionlimit
setrecursionlimit(100000)
def solve(x,y,n,m):
    try:
        done_list[(x,y)]=1
        global l
        global ki
        if x+1<m and (x+1,y) not in done_list and l[y][x+1]=='.':
            d = solve(x+1,y,n,m)
        if x-1>=0 and (x-1,y) not in done_list and l[y][x-1]=='.':
            d = solve(x-1,y,n,m)
        if y+1<n and (x,y+1) not in done_list and l[y+1][x]=='.' :
            d = solve(x,y+1,n,m)
        if y-1>=0 and (x,y-1) not in done_list and l[y-1][x]=='.' :
            solve(x,y-1,n,m)
        yes = 0
        if yes<=1 and ki>0:
            ki-=1
            l[y][x]='X'
    except Exception as inst:
        print inst
n,m,ki = map(int,raw_input().split())
l = []
for i in range(n):
    k = list(raw_input())
    l.append(k)

p = 0
x = -1
y = -1
for i in range(n):
    for j in range(m):
        if l[i][j]=='.':
            y = i
            x = j
            p=1
            break
    if p==1:
        break
done_list={}
solve(x,y,n,m)
ans = []
for i in l:
    s = ""
    for j in i:
        s+=j
    ans.append(s)

for i in ans:
    print i
