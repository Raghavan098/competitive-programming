n = input()
l = map(int,raw_input().split())
k =[]
for i in range(n):
    k.append([l[i],i])

k.sort()
# print k
if n!=1:
    if k[0][0]==k[1][0]:
        print "Still Rozdil"
    else:
        print k[0][1]+1
else:
    print 1
