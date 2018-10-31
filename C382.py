n = input()
l = map(int ,raw_input().strip().split(' '))
l.sort()
if(n==1):
    print -1
else:
    ans=[]
    if(n==2):
        if (l[1]-l[0]-1)%2==1:
            k = (l[1]-l[0])/2
            ans.append(l[0]+k)
        diff = l[1]-l[0]
        ans.append(l[0]-diff)
        ans.append(l[1]+diff)
    else:
        diff1 = None
        diff2 = None
        no = 0
        for i in range(n-1):
            if(diff1==None):
                diff1 = l[i+1]-l[i]
            if(l[i+1]-l[i]!=diff1 and l[i+1]-l[i]!=diff2):
                if(diff2==None):
                    diff2 = l[i+1]-l[i]
                else:
                    no = 1
                    break
        if(no==1):
            fjkf = 1
        elif diff2 == None:
            ans.append(l[0]-diff1)
            ans.append(l[n-1]+diff1)
        else:
            q = 0
            if diff1>diff2:
                diff1,diff2 = diff2,diff1
            if(diff2/2!=diff1) or diff2%2!=0:
                fkfk=1
            else:
                for i in range(n-1):
                    if l[i+1]-l[i]==diff2 and q==0:
                        q=1
                        ans.append(l[i]+diff1)
                    elif l[i+1]-l[i]==diff2 and q==1:
                        ans = []
                        break
    ans.sort()
    ans_f = []
    if ans!=[]:
        prev=None
        for i in ans:
            if i!=prev:
                ans_f.append(i)
                prev = i

        print len(ans_f)
        for i in ans_f:
            print i,
    else:
        print 0
