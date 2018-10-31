s = raw_input()
ans = 0
for i in range(len(s)):
    if s[i]>='0' and s[i]<='9':
        x = int(s[i])
        if(x%2==1):
            ans+=1
    elif s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u':
        ans+=1
print ans
