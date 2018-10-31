def recur(a,ans=0):
    global d
    global count
    if tuple(a) not in d:
        d[tuple(a)]=1
        count+=1
        for i in range(len(a)):
            if i<(len(a)-2) and a[i]>0 and a[i+1]>0:
                temp=[]
                for j in range(len(a)):
                    temp.append(a[j])
                temp[i]-=1
                temp[i+1]-=1
                temp[i+2]+=1
                ans+=recur(temp,ans)
            elif i==(len(a)-2) and  a[i]>0 and a[i+1]>0:
                temp=[]
                for j in range(len(a)):
                    temp.append(a[j])
                temp[i]-=1
                temp[i+1]-=1
                temp.append(1)
                ans+=recur(temp,ans)
        return ans+1
    else:
        return 0


t=input()
d={}
count=0
for _ in range(t):
    n=input()
    a=map(int,raw_input().split())
    d={}
    count=0
    recur(a)
    print count%(10**9+7)
