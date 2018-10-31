n = input()
for _ in range(n):
    s = raw_input()
    st = -1
    end = -1
    pre = "x"
    count={}
    count['A']=0
    count['B']=0
    for i in range(len(s)):
        if s[i]!='.' and st==-1:
            st = i
            pre = s[i]
            count[s[i]]+=1
        elif s[i]!='.' and st!=-1:
            end = i
            if s[i]==pre:
                count[s[i]]+=(end-st-1)
            st = i
            count[s[i]]+=1
            pre = s[i]
    print count['A'],count['B']
