n = input()
l = list(raw_input())
l.reverse()
k = ['a','e','i','o','u','y']
for i in range(n-1):
    if l[i] in k and l[i+1] in k:
        l[i] = '.'

ans = ""
for i in l:
    if i!='.':
        ans+=i

print ans[::-1]
