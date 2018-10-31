n = input()
s = "aabb"
ans = ""
for i in range(n):
    ans+=s[i%4]
print ans
