x = raw_input()
#a.deb
a =""
for i in range(len(x)):
    if x[i]!='.':
        a+=x[i]
    else:
        st = i
        break
d = ""
for i in range(st+1,len(x)):
    if x[i]!='e':
        d+=x[i]
    else:
        st = i
        break;
d+="0"*101
b = ""
for i in range(st+1,len(x)):
    b+=x[i]

ans = a
for i in range(int(b)):
    ans+=d[i]
ans+='.'
for i in range(int(b),len(d)):
    ans+=d[i]
for i in range(len(ans)-1,-1,-1):
    if ans[i]!='0':
        thi = i
        break

if ans[thi]=='.':
    thi-=1

print ans[:thi+1]
