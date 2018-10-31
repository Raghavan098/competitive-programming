n = input()
kd = [1000000,100000,10000,1000,100,10,1]
kd.reverse()
dp = [[0,'a',True],[0,'b',True],[0,'c',True],[0,'d',True],[0,'e',True],[0,'f',True],[0,'g',True],[0,'h',True],[0,'i',True],[0,'j',True]]
for i in range(n):
    s = raw_input()
    for j in range(len(s)):
        if j==0:
            dp[ord(s[j]) - 97][2] = False
        dp[ord(s[j]) - 97][0]+=kd[len(s)-1-j]

dp.sort(reverse = True)
# print dp
# print zero
done = 0
curr = 1
ans = 0
for i in range(10):
    if dp[i][2]==True and done==0:
        done = 1

    else:
        # print "yes",dp[i][1],curr
        ans+=curr*dp[i][0]
        curr+=1
    # print ans

print ans
