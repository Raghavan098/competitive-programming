def bs(x,s,e,li):
    # print s,e
    if s==e:
        if li[s][0]<=x:
            return s
        else:
            return -1
    m = s+(e-s)/2
    if x<li[m][0]:
        return bs(x,s,m,li)
    ret = bs(x,m+1,e,li)
    if ret==-1:
        return m
    else:
        return ret
n,m = map(int,raw_input().split())
l = map(int,raw_input().split())
li = []
u = [0]
i = 0
j  = 0
while(i<n-1):
    # print i,"i"
    if l[i]<=l[i+1]:
        i+=1
        continue
    j=i
    while(j<n-1):
        # print j,"j"
        if l[j]>=l[j+1]:
            j+=1
            i = j
            continue
        else:
            u.append(j)
            li.append(u)
            u = [j]
            i = j
            break
if u!=[n-1] or n==1:
    u.append(n-1)
    li.append(u)

# print li
ma = [-1]*len(li)
ma[0] = li[0][1]
for i in range(1,len(li)):
    ma[i] = max(ma[i-1],li[i][1])
get = [0]*n
get[0] = 0
curr = li[0][1]
u = 1
for i in range(1,n):
    if i<curr or i==n-1:
        get[i] = get[i-1]
    else:
        get[i] = u
        if u<len(ma):
            curr = li[u][1]
            u+=1
# print li
# print get
for i in range(m):
    x,y = map(int,raw_input().split())
    x = x-1
    y = y-1
    k = get[x]
    # print k
    if ma[k]>=y:
        print "Yes"
    else:
        print "No"
