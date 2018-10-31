n,p = map(int,raw_input().split())
s = raw_input()
if p==1:
    print "NO"
elif p==2:
    if n>2:
        print "NO"
    else:
        if n==2:
            if s=='ab':
                print 'ba'
            else:
                print "NO"
        else:
            if s=='a':
                print 'b'
            else:
                print 'NO'
else:
    done = 0
    s = list(s)
    for i in range(n-1,-1,-1):
        for j in range(ord(s[i])-95,p+1):
            temp = chr(j+96)
            a = '*'
            b = '*'
            c = '*'
            d = '*'
            if i-1>=0:
                a = s[i-1]
            if i-2>=0:
                b = s[i-2]
            if i+1<n:
                c = s[i+1]
            if i+2<n:
                d = s[i+2]
            if temp!=a and temp!=b and temp!=c and temp!=d:
                done = 1
                s[i] = temp
                break

        if done ==1:
            break
        else:
            done2 = 0
            for k in range(97,p+97+1):
                temp = chr(k)
                a = '*'
                b = '*'
                c = '*'
                d = '*'
                if i-1>=0:
                    a = s[i-1]
                if i-2>=0:
                    b = s[i-2]
                if i+1<n:
                    c = s[i+1]
                if i+2<n:
                    d = s[i+2]
                if temp!=a and temp!=b and temp!=c and  temp!=d:
                    done2 = 1
                    s[i] = temp
                    break
            if done2 == 0:
                # print "jan"
                print "NO"
                done = 2
                break
    if done == 0:
        print "NO"
    elif done ==1:

        print ''.join(s)
