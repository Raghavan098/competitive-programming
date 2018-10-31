n,m = map(int,raw_input().split())
l1 = map(int,raw_input().split())
l2 = map(int,raw_input().split())
m1 = -9999999999999999999
for i in range(len(l1)):
    for j in range(len(l2)):
        if l1[i]*l2[j]>m1:
            m1 = l1[i]*l2[j]
            curr = i

m2 =-9999999999999999999
for i in range(len(l1)):
    for j in range(len(l2)):
        if i!=curr and l1[i]*l2[j]>m2:
            m2 = l1[i]*l2[j]

print m2
