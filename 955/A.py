import math
hh,mm = map(int,raw_input().split())
l = map(int,raw_input().split())
if(hh>=20):
    k = l[2] - l[2]*0.2
    p = math.ceil((l[0]*1.0)/l[3])
    print p*k

else:
    rem = (20 - hh-1)*60 + (60 - mm)
    k = l[2] - l[2]*0.2
    p = math.ceil((l[0]*1.0+rem*l[1])/l[3])
    if p*k < math.ceil(l[0]*1.0/l[3])*l[2]:
        print p*k
    else:
        print math.ceil(l[0]*1.0/l[3])*l[2]
