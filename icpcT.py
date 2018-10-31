t = input()

def check(q,no1,no2,no3,op,flag1,flag2,flag3):
    a = list(no1)
    b = list(no2)
    c = list(no3)
    for i in range(len(no1)):
        if a[i] == '?':
            a[i]= str(q)

    for i in range(len(no2)):
        if b[i] == '?':
            b[i]= str(q)

    for i in range(len(no3)):
        if c[i] == '?':
            c[i]= str(q)


    a = ''.join(a)
    b = ''.join(b)
    c = ''.join(c)
    a = int(a)
    b = int(b)
    c = int(c)
    if flag1==1:
        a = -a
    if flag2==1:
        b = -b
    if flag3==1:
        c = -c

    if op=="*" and a*b==c:
        return True
    elif op=='-' and a-b==c:
        return True
    elif op=='+' and a+b==c:
        return True

    return False




for _ in range(t):
    s = raw_input()
    flag1 = 0
    if s[0]=='-':
        flag1 = 1
        s = s[1:]
    # print s,len(s)
    done1 = 0
    li = []
    for i in range(len(s)):
        if (s[i]=='+' or s[i]=='-' or s[i]=='*' )and done1==0:
            this1 = i
            done1 = 1
        elif s[i]=='=':
            this2 = i
        elif s[i]!='?' and s[i]!='-':
            li.append(int(s[i]))


    # print s[this1]
    no1 = s[:this1]
    op = s[this1]
    flag2 =0
    if s[this1+1]=='-':
        flag2 = 1
        no2 = s[this1+2:this2]
    else:
        no2 = s[this1+1:this2]
    flag3 = 0
    if s[this2+1]=='-':
        flag3 =1
        no3 = s[this2+2:]
    else:
        no3 = s[this2+1:]

    # print no1,no2,no3
    done = 0
    if((no1[0]!='?' or len(no1)==1) and (no2[0]!='?' or len(no2)==1) and (no3[0]!='?' or len(no3)==1) and done==0):
        if 0 not in li:
            if(check(0,no1,no2,no3,op,flag1,flag2,flag3)):
                print 0
                done =1


    if done==0:
        for i in range(1,10):
            if i not in li:
                if(check(i,no1,no2,no3,op,flag1,flag2,flag3)):
                    print i
                    done = 1
                    break


    if done==0:
        print -1
