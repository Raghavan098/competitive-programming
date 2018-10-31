h,w = map(int,raw_input().split(' '))
l = []
for i in range(h):
    k = map(int,raw_input().split(' '))
    l.append(k)
ans = 0

for i in range(h):
    for j in range(w):
        ans1=2
        print i,j
        if i==0 and j==0:
            ans1+=(2*l[i][j])
            if i>0 and l[i][j]>l[i+1][j]:
                ans1+=(l[i][j]-l[i+1][j])
            if j>0 and l[i][j]>l[i][j+1]:
                ans1+=(l[i][j]-l[i][j+1])
        if i==0 and j==w-1 and i!=j:

            ans1+=(2*l[i][j])
            if l[i][j]>l[i][j-1]:
                ans1+=(l[i][j]-l[i][j-1])
            if i>0 and l[i][j]>l[i+1][j]:
                ans1+=(l[i][j]-l[i+1][j])
        if j==0 and i==h-1:
            ans1+=(2*l[i][j])

        if j==w-1 and i==h-1 and i!=0:
            ans1+=(2*l[i][j])
        if i==0 and j!=w-1 and j!=0:
            ans1+=(l[i][j])
        if j==0 and i!=0 and i!=h-1:
            ans1+=(l[i][j])
        if i==h-1 and j!=0 and j!=w-1:
            ans1+=(l[i][j])
        if j==w-1 and i!=0 and i!=h-1:
            ans1+=(l[i][j])
        print ans1
        ans+=ans1
    print ""
print ans
