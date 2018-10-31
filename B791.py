n,m = map(int,raw_input().split(' '))
s1={}
s2={}
s3={}
s4={}
s5={}
s6={}
done =0
l=[]
for i in range(m):
    a,b = map(int,raw_input().split(' '))
    l.append((a,b))
    if a in s1:
        s3[(s1[a],b)]=0
    if b in s1:
        s3[(s1[b],a)]=0
    s1[b]=a
    s1[a]=b
# print "hello"s
for i in l:
    try:
        s3[i]=1
    except:
        pass
    try:
        s3[(i[1],i[0])]=1
    except:
        pass
#print s3
for i in s3:
    if s3[i]==0:
        done = 1
        print "NO"
        break
if done==0:
    print "YES"
