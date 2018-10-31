n = input()
s = raw_input()
cur=0
s = s+'Z'
d={}
for i in range(n+1):
    if s[i] not in d and s[i].isupper()==False:
        d[s[i]]=1
    elif s[i].isupper() ==True:
        if len(d)>cur:
            cur = len(d)
        d={}
    # print d,len(d),s[i],s[i].isupper()
print cur
