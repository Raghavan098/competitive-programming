n = input()
m = input()
curr = 1
count = 0
while(curr<=m and count<n):
    curr = curr*2
    count+=1
print m%curr
