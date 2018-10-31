n = input()
l = map(int,raw_input().split())
st = [l[0]]
for i in range(1,n):
    st.append(l[i]+st[i-1])
# print st
k = [1]*(max(st)+1)
i = 0
count=1
# print k
for j in range(1,max(st)+1):
    k[j] = count
    if j+1<max(st)+1 and j+1>=st[i]:
        count+=1
        i+=1
m = input()
l = map(int,raw_input().split())
for i in l:
    print k[i-1]
