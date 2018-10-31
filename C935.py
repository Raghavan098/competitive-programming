R,x1,y1,x2,y2 = map(int,raw_input().split())
if((x1 - x2)**2 + (y1 - y2)**2>=R*R):
    print x1,y1,R

else:
    if(x1!=x2):
        p = ((x1- x2)**2)*1.0
        r = (R**2)*1.0
        q = ((y2 - y1)**2)*1.0
        m = (y2 - y1)*1.0/(x2 - x1)
        xp = (R/((m**2+1)**0.5))+x1
        yp = m*(xp - x1)+y1
        xn = -xp+2*x1
        yn = m*(xn - x1)+y1
        xc1 = (xp+x2)/2
        yc1 = (yp+y2)/2
        xc2 = (xn+x2)/2
        yc2 = (yn+y2)/2
        # print xc1,yc1,xc2,yc2
        area1  = (x2 - xp)**2+(y2 - yp)**2
        area2  = (x2 - xn)**2+(y2 - yn)**2
        if area1>area2:
            print xc1,yc1,(((xp - x2)**2+(yp - y2)**2)**0.5)/2
        else:
            print xc2,yc2,(((xn - x2)**2+(yn - y2)**2)**0.5)/2
    else:
        xp = x1*1.0
        yp = R+(y1)*1.0
        xn = (x1)*1.0
        yn = -R+(y1)*1.0
        xc1 = (xp+x2)/2
        yc1 = (yp+y2)/2
        xc2 = (xn+x2)/2
        yc2 = (yn+y2)/2
        # print xc1,yc1,xc2,yc2
        area1  = (x2 - xp)**2+(y2 - yp)**2
        area2  = (x2 - xn)**2+(y2 - yn)**2
        if area1>area2:
            print xc1,yc1,(((xp - x2)**2+(yp - y2)**2)**0.5)/2
        else:
            print xc2,yc2,(((xn - x2)**2+(yn - y2)**2)**0.5)/2
