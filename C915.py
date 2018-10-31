
a = list(raw_input())
b = list(raw_input())
d = {}
for i in a:
    if i not in d:
        d[i]= 1
    else:
        d[i]+=1
if a==b:
    print ''.join(b)
elif len(b)>len(a):
    l= sorted(a)
    l.reverse()
    ans = ""
    for j in l:
        ans+=j

    print ans
    # print ''.join(sorted(a).reverse())
else:
    i = 0
    ans = ""
    while(i<len(b)):
        # print b,d,type(i)
        if b[i] in d and d[b[i]]>0:
            ans+=b[i]
            # print "asd"
            d[b[i]]-=1
            i+=1
        else:
            m = -1
            mi = ""
            done  = 0
            # print i,d
            for j in d:
                if j<b[i] and d[j]>0 and int(j)>m:
                    m = int(j)
                    mi = j
                    done = 1

            if m!=-1:
                d[mi]-=1
                ans+=mi
            elif done==0:
                curr = i-1
                # print curr,"curr"
                while(curr>=0):
                    # print curr
                    # print d,ans
                    m = -1
                    mi = ""
                    for j in d:
                        # print
                        if j<b[curr] and d[j]>0 and int(j)>m:
                            m = int(j)
                            mi = j
                    # print mi
                    if m!=-1:
                        # print m,mi,curr,ans
                        done = 1
                        ans = list(ans)
                        d[ans[curr]]+=1
                        ans[curr] = mi
                        d[ans[curr]]-=1
                        ans = "".join(ans)
                        # print ans
                        break
                    else:
                        # print curr
                        d[ans[curr]]+=1
                        ans = ans[:len(ans)-1]
                        curr-=1

            if done==1:
                break
    temp = []
    for j in d:
        while d[j]>0:
            temp.append(j)
            d[j]-=1
    temp.sort(reverse=True)
    for j in temp:
        ans+=j
    print ans
