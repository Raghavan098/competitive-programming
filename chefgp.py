for _ in range(input()):
    s=raw_input()
    x,y=map(int,raw_input().split(' '))
    ca=0
    cb=0
    for i in s:
        if i=='a':
            ca+=1
        else:
            cb+=1
    ans =""
    if ca!=cb and ca!=0 and cb!=0:
        d = max(ca,cb)/(min(ca,cb)+1)
        if ca>cb:
            mx = 'a'
            mn = 'b'
            mc = x
            count1 = ca
            count2 = cb
        else:
            mx = 'b'
            mn = 'a'
            mc = y
            count1 = cb
            count2 = ca
        # print mx,mn,d
        # d = len(s)/max(ca,cb)
        # d = min(d,mc)

        if True:
            for i in range(1,len(s)+1):
                if i%(d+1)!=0 and count1>0:
                    ans+=mx
                    count1-=1
                elif count2>0:
                    ans+=mn
                    count2-=1
                elif count1>0:
                    ans+=mx
                    count1-=1
        # print ans
        count=0
        ans2 = ""
        starc = 0
        for i in range(len(s)):
            temp = ans[i]
            if ans[i]==mx:
                count+=1
            else:
                count = 0
            if count > mc:
                temp = '*'+temp
                count = 1
                starc+=1
            ans2+=temp
        # print d
        d = max(ca,cb)/(min(ca,cb)+1)+1
        # print d
        if ca>cb:
            mx = 'a'
            mn = 'b'
            mc = x
            count1 = ca
            count2 = cb
        else:
            mx = 'b'
            mn = 'a'
            mc = y
            count1 = cb
            count2 = ca
        # print mx,mn,d
        # d = len(s)/max(ca,cb)
        # d = min(d,mc)
        ans =""
        # print count1,count2
        if True:
            for i in range(1,len(s)+1):
                if i%(d+1)!=0 and count1>0:
                    ans+=mx
                    count1-=1
                elif count2>0:
                    ans+=mn
                    count2-=1
                elif count1>0:
                    ans+=mx
                    count1-=1
        # print ans
        count=0
        starc2 =0
        ans3 = ""
        for i in range(len(s)):
            temp = ans[i]
            if ans[i]==mx:
                count+=1
            else:
                count = 0
            if count > mc:
                temp = '*'+temp
                count = 1
                starc2+=1
            ans3+=temp
        # print ans2
        # print ans3
        if starc>starc2:
            ans2 = ans3
    elif ca==cb:
        ans2=""
        for i in range(len(s)):
            if i%2==0:
                ans2+='a'
            else:
                ans2+='b'
    elif cb==0:
        ans2="a"
        for i in range(1,len(s)):
            if i%x==0:
                ans2+='*a'
            else:
                ans2+='a'
    elif ca==0:
        ans2="b"
        for i in range(1,len(s)):
            if i%y==0:
                ans2+='*b'
            else:
                ans2+='b'
    print ans2
