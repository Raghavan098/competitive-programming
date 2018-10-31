n,m,k = map(int,raw_input().split())
l = map(int,raw_input().split())
time = [0]*1000010
for i in l:
    time[i] = 1
for i in range(1000010):
    if time[i] ==1:
        s = i
        break
# print time
i = s
ma = max(l)
count = 0
ans = 0
for q in range(1,ma+1):

    if time[q]==1:
        count+=1
    if count==k and q<=i+m:
        ans+=1
        time[q] = 0
        count -=1
    if i+m-1==q:
        if time[i]==1:
            count-=1
        i+=1
    # print count,i,q
print ans
