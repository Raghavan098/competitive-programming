n = input()
l = map(int,raw_input().split())
l.sort()
k = [[1,l[0]]]
curr = 0
for i in range(1,n):
    if l[i]==l[i-1]:
        k[curr][0]+=1
    else:
        curr+=1
        k.append([1,l[i]])
done=  0
for i in range(len(k)-1,-1,-1):
    if k[i][0]%2==1:
        done = 1
        break
if done==0:
    print "Agasa"
else:
    print "Conan"
