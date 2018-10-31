n = input()
l = [0]*(1001)
l[0] = 1
l[1] = 1
l[2] = 1
l[3] = 1
curr = 5
prvcurr = 3
while True:
    l[curr] = 1
    x = curr
    curr+=prvcurr
    prvcurr = x
    if curr>n+1:
        break
s = ""
for i in range(1,n+1):
    if l[i]==1:
        s+="O"
    else:
        s+='o'
print s
