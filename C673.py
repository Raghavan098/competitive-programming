n = input()
l = map(int,raw_input().split(' '))
ans=[0]*n
for i in range(n):
    tp=[0]*n
    mx = 0
    mxele = i
    for j in range(i,n):
        tp[l[j]-1]+=1
        if tp[l[j]-1]>mx:
            mx = tp[l[j]-1]
            mxele =j
            ans[l[j]-1]+=1
        elif tp[l[j]-1]==mx:
            ans[min(l[j],l[mxele])-1]+=1
            if l[mxele]>l[j]:
                mxele=j
        else:
            ans[l[mxele]-1]+=1

for i in ans:
    print i,
