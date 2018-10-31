l1 = sum(map(int,raw_input().split()))
l2 = sum(map(int,raw_input().split()))
n = input()
s1 = l1/5
if l1%5!=0:
    s1+=1
s2 = l2/10
if l2%10!=0:
    s2+=1
if s1+s2<=n:
    print "YES"
else:
    print "NO"
    
