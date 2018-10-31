n = input()
if(sum(map(int,raw_input().split()))%n==0):
    print n;
else:
    print n-1
