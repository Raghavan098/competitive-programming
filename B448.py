s = list(raw_input())
t = list(raw_input())
s1 = [0]*26
s2 = [0]*26
for i in s:
    s1[ord(i)-ord('a')]+=1
for i in t:
    s2[ord(i)-ord('a')]+=1
done  = 0
for i in range(26):
    if s2[i]>s1[i]:
        print "need tree"
        done  = 1
        break
if done==0:
    k =0
    for i in range(26):
        if s1[i]!=s2[i]:
            k =1
            break
    if k==0:
        print "array"
        done = 1

    if done==0:
        start = t[0]
        curr = 0
        for i in s:
            if i==start:
                curr+=1
                if curr<len(t):
                    start = t[curr]
                else:
                    break
        # print curr
        if curr==len(t):
            print "automaton"
        else:
            print "both"
