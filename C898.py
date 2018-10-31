def get_len(x):
    s = 0
    while(x>0):
        s+=1
        x = x/10
    return s
n = input()
l = []
d = {}
for i in range(n):
    k = raw_input().split()
    si = int(k[1])
    k[1] = int(k[1])
    if k[0] not in d:
        d[k[0]] = []
    for j in  range(2,si+2):

        k[j] = int(k[j])
        d[k[0]].append(k[j])
    l.append(k)
for lis in d:
    for i in range(len(d[lis])):
        temp = d[lis][i]
        q = get_len(d[lis][i])
        q = 10**q
        for j in range(len(d[lis])):
            if i!=j:
                if d[lis][j]%q==temp:
                    d[lis][i]=-1
                    break
print len(d)
for i in d:
    print i,
    u = []
    for j in d[i]:
        if j!=-1:
            u.append(j)
    print len(u),
    for j in u:
        print j,

    print ""
