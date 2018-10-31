n = input()
l = []
for i in range(n):
    k = raw_input().split(' ')
    k.append(int(k[1]))
    l.append(k)
ans = 10**9+1
ansst = ""
for i in range(n):
    d = {}
    d['4']=0
    d['7']=0
    anythin = 0
    for j in l[i][1]:
        if j=='7' or j=='4':
            d[j]+=1
        else:
            anythin = 1
            break
    if d['4']==d['7'] and d['4']>0 and anythin==0:
        if l[i][2]<ans:
            ans = l[i][2]
            ansst = l[i][0]
if ansst!="":
    print ansst
else:
    print -1
