n = input()
count = 0
while(n>0):
    n-=1
    k = map(int,raw_input().split())
    x = sum(k)
    if x>=2:
        count+=1

print count
