t = raw_input()
k = raw_input()
full = []
s1 = "qwertyuiop"
s2 = "asdfghjkl;"
s3 = "zxcvbnm,./"
full.append(s1)
full.append(s2)
full.append(s3)
ans = ""
for i in k:
    done = 0
    for j in full:
        for k in range(len(j)):
            if j[k]==i:
                done = 1
                if t=='R':
                    ans+=j[k-1]
                else:
                    ans+=j[k+1]
                break
        if done==1:
            break
print ans
