s = raw_input()
d = {}

for i in s:
    if i not in d:
        d[i] =1
    else:
        d[i]+=1
# print d,len(d)
if len(d)==2:
    for i in d:
        d[i]-=1
    done = 0
    for i in d:
        if d[i]==0:
            done =1
    if done==0:
        print "Yes"
    else:
        print "No"
elif len(d)==3:
    done = 0
    for i in d:
        if d[i]!=1:
            done = 1
    if done == 0:
        print "No"
    else:
        print "Yes"

elif len(d)==4:
    print "Yes"
else:
    print "No"
