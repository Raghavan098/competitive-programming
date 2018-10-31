import math
n,k=  map(int,raw_input().split())
ln = len(bin(n)) - 2
if k == 1:
    print(n)

else:
    print((2 ** ln) - 1)
# print s
