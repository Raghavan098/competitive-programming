a,b,c = map(int,raw_input().strip().split(' '))
temp = a*10000000
ans = temp/b

ans%=10000000
p=0
count = 0
print ans
j = 6
while(count<=6):
    ans%=10**(j+1)
    k = ans/10**j

    print k,ans
    count+=1
    if k==c:
        p=1
        print count
        break
    j-=1

if p==0:
    print -1
