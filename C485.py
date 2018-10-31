def int2bin(i):
    if i == 0: return "0"
    s = ''
    while i:
        if i & 1 == 1:
            s = "1" + s
        else:
            s = "0" + s
        i /= 2
    return s

n = input()
for i in range(n):
    l,r = map(int,raw_input().split())
    s1 = int2bin(l)
    s2 = int2bin(r)
    if r==2**(len(s2))-1:
        print 2**(len(s2))-1
        continue
    if(len(s1)<len(s2)):
        if r==2**(len(s2))-1:
            print 2**(len(s2))-1
        else:
            print 2**(len(s2)-1)-1

    else:
        curr = l
        done = 1
        for i in range(len(s1)-1,-1,-1):
            if s1[i]=='0':
                temp = curr+2**(len(s1)-1-i)
                if temp>r:
                    print curr
                    done = 0
                    break
                else:
                    curr = temp



        if done==1:
            print curr
