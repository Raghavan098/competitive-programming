def check(l1,l2):
    for i in range(len(l1)):
        if l1[i] != l2[i]:
            return False
    return True
n,l =map(int,raw_input().split(' '))
l1 = map(int ,raw_input().split(' '))
l2 = map(int,raw_input().split(' '))
c =0
for i in range(1,l+1):
    for j in range(n):
        l1[j] = (l1[j]+1)%l
    # print l1
    # print l2
    # print ""
    if check(sorted(l1),l2)==True:
        c =1
        print "Yes"
        break
if c==0:
    print "No"
