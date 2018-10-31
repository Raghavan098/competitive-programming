n = input()
l = map(int,raw_input().split())
l.sort()
ans = [0]*n
on = [0]*n
j = 1
i = 0
while(i<n-1):
    if j<n and l[i]<l[j] and ans[j]==0:
        ans[j] = 1
        on[i]=1
        i+=1
    j+=1
    if j>=n:
        break

count = 0
for i in on:
    if i==0:
        count+=1
print count
