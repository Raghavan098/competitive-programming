s = raw_input()
p = ['Y']*len(s)
prev = s[0]
count = 1
prevcount=0
for i in range(1,len(s)):
    if s[i]==prev:
        count+=1
    if s[i]==prev and count >=3:
        p[i]="X"
        count-=1
    elif s[i]==prev and count==2 and prevcount==2:
        p[i]='X'
        count-=1
    elif s[i]!=prev:
        prevcount = count
        count =1
        prev = s[i]
k=""
for i in range(len(s)):
    if p[i] != "X":
        k+=s[i]
print k
