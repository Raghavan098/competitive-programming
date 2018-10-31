n = input()
l=[]
ac = 0
bc = 0
for i in range(n):
    x,y = map(int ,raw_input().strip().split(' '))
    l.append([x,y])
    if x>0:
        ac+=1
    elif x<0:
        bc+=1

if ac<=1 or bc<=1:
    print "Yes"
else:
    print "No"
