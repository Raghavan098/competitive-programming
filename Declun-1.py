t = input()
while(t>0):
    t-=1
    l = ['mon','tues','wed','hurs','fri','sat','sun']
    k = raw_input().split()
    k[0] = int(k[0])
    week = k[0]/7
    ans = [week]*7
    rem = k[0]%7
    for i in range(7):
        if l[i] == k[1]:
            curr = i
            while(rem>0):
                ans[curr%7]+=1
                curr+=1
                rem-=1

    for i in ans:
        print i,
    print ""
