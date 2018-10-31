s = raw_input()
l = []
r = []
for i in  range(len(s)):
    if s[i]=='l':
        l.append(i+1)
    else:
        r.append(i+1)

l.reverse()
for i in r:
    print i
for i in l:
    print i
