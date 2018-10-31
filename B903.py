h1,a1,c1 = map(int,raw_input().split())
h2,a2 = map(int,raw_input().split())
count = 0
arr=[]
while(h2>0):
    # print h2
    if h1-a2>=1 or h2-a1<=0:
        count+=1
        arr.append(1)
        h1-=a2
        h2-=a1

    else:
        count+=1
        h1+=c1
        h1-=a2
        arr.append(2)

print len(arr)
for i in arr:
    if i==2:
        print "HEAL"
    else:
        print "STRIKE"
