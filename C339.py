s = raw_input()
m = input()
k = []
for i in range(len(s)):
    if s[i]=='1':
        k.append(i+1)
g = 0
d = {}
currd = 0
ans = []
prev = -1
for i in range(m):
    if [currd,prev in d and d[currd]!=prev:
        prev = d[currd]
        ans.append(d[currd])
    else:

        temp = 1000
        ele = -1
        for j in k:
            if j - currd<temp and j!=prev and j-currd>0:
                temp = j-currd
                ele = j
        # print currd,ele
        if ele!=-1:
            ans.append(ele)
            d[currd] = ele
            currd = temp
            prev = ele
        else:
            break

if len(ans)<m:
    continue
else:
    g = 1
    print "YES"
    for i in range(m):
        print ans[i],
    print ""
    break
if g==0:
    print "NO"
