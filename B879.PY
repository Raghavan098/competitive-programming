n,k = map(int,raw_input().split(' '))
l = map(int,raw_input().split(' '))
count = 0
winner = 0
done =0
for i in range(1,n):
    if(l[winner]<l[i]):
        winner = i
        count=1
    else:
        count+=1
    if count==k:
        done = 1
        print l[winner]
        break
if done ==0:
    k = max(l)
    print k
