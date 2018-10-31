def get(curp,fullTank,a,b,f):
    global curfueltime
    if curp ==a:
        if(b>=a+f):
            return b-a
        else:
            curfueltime+=1
            return fullTank-f
    else:
        if b>=a+(a-f):
            return b-a
        else:
            curfueltime+=1
            return fullTank -(a-f)

a,b,f,k = map(int,raw_input().strip().split(' '))
d={}
curdistfuel = -f
curfuel = b
currounds = 0
curfueltime=0
curpos = 0
curdir = 1
done =0
temp = b
if b<f or b<a-f:
    done = 1
if done==0:
    for i in range(k-1):
        temp = get((i%2)*a,b,a,temp,f)
        # print temp
        if temp <0:
            done =1
            break
    if k%2 ==0:
        if temp>=a:
            pass
        elif temp>=a-f:
            curfueltime+=1
        else:
            done =1
    else:
        if temp>=a:
            pass
        elif temp>=f:
            curfueltime+=1
        else:
            done=1
if done == 0:
    print curfueltime
else :
    print -1
