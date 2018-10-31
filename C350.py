n = input()
l = []
for i in range(n):
    x,y = map(int,raw_input().split())
    l.append([abs(x)+abs(y),x,y])
l.sort(key=lambda x: x[0])
ans=[]
for i in l:

    if i[1]>0:
        ans.append(["1",i[1],"R"])
    elif i[1]<0:
        ans.append(["1",abs(i[1]),"L"])

    if i[2]>0:
        ans.append(["1",i[2],"U"])
    elif i[2]<0:
        ans.append(["1",abs(i[2]),"D"])
    ans.append(["2"])

    if i[1]>0:
        ans.append(["1",i[1],"L"])
    elif i[1]<0:
        ans.append(["1",-1*i[1],"R"])

    if i[2]>0:
        ans.append(["1",i[2],"D"])
    elif i[2]<0:
        ans.append(["1",-1*i[2],"U"])
    ans.append(["3"])
print len(ans)
for i in ans:
    for j in i:
        print j,
    print ""
