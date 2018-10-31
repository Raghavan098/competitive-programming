from sys import getrecursionlimit, setrecursionlimit
setrecursionlimit(10000)
def recc(prev, diff, length, arr, ans, pos):
    global d
    global ki
    if ki==0:
        # print ans,pos,prev,diff
        if (prev,diff,length) in d:
            return 1
        if length == 0:

            ki = 1
            print "YES"
            for i in range(pos):
                print ans[i],
            return 0
        for i in arr:
            if i!=prev and i>diff:

                ans[pos] = i
                recc(i,i-diff,length-1,arr,ans, pos+1)
                d[(i,i-diff,length-1)]=1
    else:
        return 0

d = {}
ans = [0]*1004
ki = 0
s = raw_input()
m = input()
k = []
for i in range(len(s)):
    if s[i]=='1':
        k.append(i+1)
recc(0,0,m,k,ans,0)
if ki==0:
    print "NO"
