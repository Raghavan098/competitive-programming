n,a,b = map(int,raw_input().split())
s = raw_input()
s = s+'*'
c = 0
ans = 0
for i in s:
    if i=='.':
        c+=1
    else:
        # print c
        if c%2==0:
            ac = min(a,c/2)
            bc = min(b,c/2)
            ans +=(ac+bc)
            a-=ac
            b-=bc
        else:
            ac = min(a,c/2+1)
            bc = min(b,c/2+1)
            if ac==c/2+1 and bc==c/2+1:
                # print "hello"
                if a>b:
                    ans +=(ac+bc-1)
                    a-=ac
                    b-=(bc-1)
                else:
                    ans +=(ac+bc-1)
                    a-=(ac-1)
                    b-=(bc)
            else:
                ans +=(ac+bc)
                a-=ac
                b-=bc
        # print ac,bc,a,b,ans
        c = 0

print ans
