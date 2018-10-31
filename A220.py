n = input()
l = map(int,raw_input().split())
k = sorted(l)
count = 0
for i in range(n):
    if l[i]!=k[i]:
        count+=1
# print count
if count>2:
    print "NO"
else:
    print "YES"
