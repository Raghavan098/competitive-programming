n = input()
l = map(int,raw_input().strip().split(' '))
l.sort()
prev = l[0]
ans_list = [prev]
top_list = [prev]
count = [0]*100
count[0]=1
length = 1
for i in range(1,n):
    done=0
    for j in range(length):
        if l[i]>top_list[j]:
            top_list[j]=l[i]
            count[j]+=1
            done = 1
            break
    if done==0:
        count[length]+=1
        ans_list.append(l[i])
        top_list.append(l[i])
        length+=1
print ans_list
print top_list
print count
i = 0
j = length-1
while(i<j):
    while(count[j] and i<j):
        if ans_list[i]>0:
            count[j]-=1
            ans_list[i]-=1
        else:
            i+=1
    if count[j]==0:
        j-=1

print count
print ans_list
i = 0
while( i<100 and count[i]!=0 ):

    i+=1
    # print i
print i
