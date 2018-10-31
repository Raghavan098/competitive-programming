n = input()
l = map(int,raw_input().split(' '))
l.append(-1)
l.append(-2)
ans = []
p = [l[0],0]
for i in range(n+1):
    if l[i]>l[i+1]:
        if(i>0):
            p.append([i-1,l[i-1]])
            ans.append(p)
        p=[l[i],i]
print ans
