def solve(x,y,n,m,path_list,l):
    global done_list
    # print path_list
    global shtpath
    global lenp
    done_list[(x,y)]=1
    if y==n-1:
        if len(path_list)<lenp:
            lenp = len(path_list)
            shtpath = []
            for i in path_list:
                shtpath.append(i)
        return True
    if x+1<m and (x+1,y) not in done_list and l[y][x+1]=='.':
        path_list.append([x+1,y])
        d = solve(x+1,y,n,m,path_list,l)
        path_list.pop()
    if x-1>=0 and (x-1,y) not in done_list and l[y][x-1]=='.':
        path_list.append([x-1,y])
        d = solve(x-1,y,n,m,path_list,l)
        path_list.pop()
    if y+1<n and (x,y+1) not in done_list and l[y+1][x]=='.' :
        path_list.append([x,y+1])
        d = solve(x,y+1,n,m,path_list,l)
        path_list.pop()
    if y-1>=0 and (x,y-1) not in done_list and l[y-1][x]=='.' :
        path_list.append([x,y-1])
        solve(x,y-1,n,m,path_list,l)
        path_list.pop()

n,m,ki = map(int,raw_input().split())
l = []
for i in range(n):
    k = list(raw_input())
    l.append(k)
useless_list = []
done_list={}
path_list=[]
p = 0
for i in range(n):
    for j in range(m):
        if l[i][j]=='.':
            y = i
            x = j
            p=1
            break
    if p==1:
        break
shtpath = []
lenp = n*m+5
path_list.append([x,y])
solve(x,y,n,m,path_list,l)
for i in shtpath:
    l[i[1]][i[0]]='M'
for j in range(m):
    if 1<n and l[0][j]=='M' and l[1][j]!='M':
        l[0][j]='.'
# for i in l:
#     print i
for i in range(n):
    for j in range(m):
        if l[i][j]=='.':
            useless_list.append([j,i])
for i in range(ki):
    l[useless_list[i][1]][useless_list[i][0]] = 'X'
for i in range(n):
    for j in range(m):
        if l[i][j]=='M':
            l[i][j] = '.'
ans = []
for i in l:
    s = ""
    for j in i:
        s+=j
    ans.append(s)

for i in ans:
    print i
