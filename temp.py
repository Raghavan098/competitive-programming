x, y = map(int, raw_input().split())
a1 = ""
b1 = ""
temp = x
while(temp > 8):
    a1 += "8"
    b1 += "1"
    temp-=8
a1 += "9"
b1 += "1"
curr = len(b1)
while(curr < x):
    b1 = "9" + b1
    curr += 9
print a1
print b1
