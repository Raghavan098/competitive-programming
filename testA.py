def search(i,s,d,count):
    global ans
    global dic
    if i not in dic:
        dic[i] = count
        # print i,count
        if i==n-1:
            if count<ans:
                ans = count
            return
        for j in range(d,0,-1):
            if i+j<len(s) and s[i+j]=='1':
                search(i+j,s,d,count+1)
    if i in dic:

        if count<dic[i]:
            # print i,count
            if i==n-1:
                if count<ans:
                    ans = count
                return
            for j in range(d,0,-1):
                if i+j<len(s) and s[i+j]=='1':
                    search(i+j,s,d,count+1)

n,d = map(int,raw_input().split())
s = raw_input()
ans = 999999999999
count = 0
dic = {}
search(0,s,d,count)
if ans==999999999999:
    print -1
else:
    print ans
