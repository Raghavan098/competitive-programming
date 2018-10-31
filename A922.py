x,y = map(int,raw_input().split())

if x==0 and y==0:
    print "No"
elif y-x>1:
    print "No"
else:
    if y>1:
        if (x - (y-1))%2==0:
            print "Yes"
        else:
            print "No"
    else:
        if x!=0:
            print "No"
        else:
            print "Yes"
