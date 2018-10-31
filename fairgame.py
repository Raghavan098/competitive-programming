n = input()
l=[]
for _ in range(n):
    l.append(input())
l.sort()
done = 0
for i in range(n/2-1):
    if l[i]!=l[i+1]:
        done = 1
        break
for i in range(n/2,n-1):
    if l[i]!=l[i+1]:
        done =1
        break

if done ==1:
    print "NO"
elif l[0]==l[n/2]:
    print "NO"
else:
    print "YES"
    print l[0],l[n/2]
