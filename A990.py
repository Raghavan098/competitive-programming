n,m,a,b = map(int,raw_input().split())
if(n%m==0):
    print 0
else:

    rem = n%m
    m1 = rem*b
    m2 = (m - rem)*a
    print min(m1,m2)
