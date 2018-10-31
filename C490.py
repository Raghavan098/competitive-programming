s = raw_input().strip()
i,j = map(int,raw_input().strip().split(' '))
l1=[]
curr = 0
for c in xrange(len(s)):
    k = int(s[c])
    curr = curr*10 +k
    curr = curr%i
    l1.append(curr)
l2 = []
curr = 0
lne=0
for c in xrange(len(s)-1,-1,-1):
    k = int(s[c])
    curr +=k*(10**lne)
    lne+=1
    curr = curr%j
    l2.append(curr)
curri = -1
l2.reverse()
p=0
for i in xrange(len(s)-2,-1,-1):
    if l1[i]==0 and l2[i+1]==0:
        curri = i
        break
    if i!=0 and l2[i]==0 and l1[i-1]==0:
        p=1
        curri = i
        break
if p==0:
    a1 = s[0:curri+1]
    a2 = s[curri+1:]
else:
    a1 = s[0:curri]
    a2 = s[curri:]
here = 0
if here==-1 or curri==-1 or a2[0]=='0':
    if here==-1 or curri ==-1 or a2[0]=='0':
        print "NO"
    else:
        print "YES"
        print a1
        print a2
else:
    print "YES"
    print a1
    print a2
