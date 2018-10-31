n=input()
l1 = map(int,raw_input().split(' '))
l2 = map(int ,raw_input().split(' '))
l3 = sorted(l1)
l4 = sorted(l2)
d={}
l4.reverse()
index = {}
for i in range(n):
    if l4[i] not in index:
        index[l4[i]]=0
    if l4[i] not in d:
        d[l4[i]] = [l3[i]]
    else:
        d[l4[i]].append(l3[i])
for i in l2:
    print d[i][index[i]],
    index[i]+=1
