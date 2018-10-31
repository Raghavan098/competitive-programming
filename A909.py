s = raw_input().split()
curr = s[0][0]+s[1][0]
for i in range(len(s[0])):
    for j in range(len(s[1])):
        u = ""
        for l in range(i+1):
            u+=s[0][l]
        v = ""
        for l in range(j+1):
            v+=s[1][l]
        temp = u+v
        k = 0
        while(k<min(len(temp),len(curr))):
            if temp[k]<curr[k]:
                curr = temp
                break
            k+=1
        if k==min(len(temp),len(curr)):
            if len(temp)<len(curr):
                curr = temp
print curr
