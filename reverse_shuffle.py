st = list(raw_input())
l1=[]
l2=[]
s=sorted(st)
prev=""
for i in s:
    if i!=prev:
        l1.append(i)
        prev=i
    else:
        l2.append(i)
        prev = ""
# print l1
d = {}
count={}
for i in l1:
    if i not in d:
        d[i]=1
        count[i]=1
    else:
        count[i]+=1
        d[i]+=1
ans=[]
d['X']=999999
# print d
prevs = len(s)-1
k1={}
d2={}
# print count
while(len(ans)!=len(l1)):
    i=0
    while(i<len(l1)):
        for w in k1:
            d2[w]=k1[w]
        # print l1,l1[i]
        # print st,prevs
        # print "ans",ans
        if l1[i]!='X':
            for j in range(prevs,-1,-1):
                # print l1[i],st[j]
                if l1[i]==st[j]:
                    # print "yes"
                    ans.append(l1[i])
                    count[l1[i]]=count[l1[i]]-1
                    l1[i]='X'
                    st[j]='X'
                    i=0
                    prevs = j-1
                    k1={}
                    for w in d2:
                        k1[w]=d2[w]
                    # print k1

                    if l1[i]=='X':
                        count['X']=0

                    # print count,l1[i]
                    break
                if st[j] not in d2:
                    d2[st[j]]=0

                # print d2,l1[i],st[j]
                if d[st[j]]==d2[st[j]] and count[st[j]]>0:
                    # print st[j],d,d2,k1
                    k2={}
                    for w in k1:
                        d2[w]=k1[w]
                    break
                d2[st[j]]+=1

        # if(len(ans)>=6):
        #     print "here"
        #     print d
        #     print k1
        #     print count
        #     print l1
        #     print st,prevs
        #     break
        i+=1
    # if(len(ans)>=6):
    #     print "here"
    #     print d
    #     print k1
    #     print count
    #     print l1
    #     print st,prevs
    #     break
# print st
stan=""
# print ans
for i in ans:
    stan+=i
print stan
