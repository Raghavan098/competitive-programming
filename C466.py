n = input()
l = map(int ,raw_input().strip().split(' '))
done =0
for i in l:
    if i!=0:
        done =1
        break
if sum(l)%3 !=0:
    print 0
elif done==0:
    print ((n-1)*(n-2))/2
else:
    s = sum(l)/3
    n1 = 1
    cur = -1
    temp = 0
    for i in range(n):
        temp+=l[i]
        if temp==s:
            cur =i
            break
    if cur ==-1:
        print 0

    else:
        for i in range(cur+1,n):
            if l[i]==0:
                n1+=1
            else:
                break

        temp = 0
        n2 =1
        cur =-1
        for i in range(n-1,-1,-1):
            temp+=l[i]
            if temp == s:
                cur = i
                break
        for i in range(cur-1,0,-1):
            if l[i]==0:
                n2+=1
            else:
                break
        print n1*n2
