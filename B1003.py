a,b,x = map(int,raw_input().split())
y = x
x = (x + 1)/2
if a>=b:
    temp = "01"*x
    a-=(x)
    b -=(x)
    # print temp
    for i in range(a -1):
        temp = "0"+temp
    for i in range(b):
        temp += "1"

    # print a,b,temp
    if y%2==0:
        temp += "0"
        a -= 1
    elif (a-1)>=0:
        temp = "0" + temp
    print temp

else:

    temp = "10"*x

    a-=(x)
    b -=(x)
    # print temp
    for i in range(b - 1):
        temp = "1"+temp
    for i in range(a):
        temp += "0"

    if y%2==0:
        temp += "1"
        b -= 1
    elif (b-1)>=0:
        temp = "1" + temp
    print temp
