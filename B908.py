def check(i,j,k,l,p,q):
    global li,x,n,m
    curr = 'S'
    currin = 0
    while(curr!='E'):
        if int(x[currin])==i:
            p-=1
        elif int(x[currin])==j:
            p+=1
        elif int(x[currin])==k:
            q-=1
        else:
            q+=1
        if p>=n or q>=m or p<0 or q<0:
            return False
        if li[p][q]=='#':
            return False
        currin+=1
        if li[p][q]!='E' and currin==len(x):
            return False
        if li[p][q]=='E':
            return True
    return True

n,m = map(int,raw_input().split())
li = []
for i in range(n):
    x = list(raw_input())
    li.append(x)
x = raw_input()
q = -1
p = -1
for i in range(n):
    for j in range(m):
        if li[i][j]=='S':
            q = j
            p = i
            break
    if q!=-1:
        break
ans = 0
for i in range(4):
    for j in range(4):
        for k in range(4):
            for l in range(4):
                if i!=j and k!=j and i!=k and k!=l and i!=l and j!=l:
                    if check(i,j,k,l,p,q)==True:
                        ans+=1
print ans
