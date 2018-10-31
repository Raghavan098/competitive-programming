import math
t = input()
for _ in range(t):
    l1 = raw_input()
    l = float(l1)
    C = int(l)
    rem = l-C
    if C!=0:
        length = len(l1)-len(str(C))-1
    elif l1[0]=='0':
        length = len(l1)-2
    else:
        length = len(l1)-1
    # print rem,length,C,l
    if rem==0:
        ans = str(C)+"\""
        print ans
        continue
    for i in range(1,8):
        x = 2**i
        to_check = round(x*rem)
        val = (to_check*1.0)/x
        param = "."+str(length)+"f"
        # print val,to_check,x,float(format(val,param)),rem,str(rem)==str(float(format(val,param))),str(val)[:length+2],float(str(val)[:length+2])+pow(10,-length)
        if str(float(format(val,param)))==str(rem):
            if C!=0:
                ans  = str(C)+" "+str(int(to_check))+"/"+str(x)+"\""
            else:
                ans  = str(int(to_check))+"/"+str(x)+"\""
            print ans
            # print C,int(to_check)
            break
        elif str(float(str(val)[:length+2]))==str(rem):
            if C!=0:
                ans  = str(C)+" "+str(int(to_check))+"/"+str(x)+"\""
            else:
                ans  = str(int(to_check))+"/"+str(x)+"\""
            print ans
            # print C,int(to_check)
            break
        elif str(float(str(val)[:length+2])+pow(10,-length))==str(rem):
            if C!=0:
                ans  = str(C)+" "+str(int(to_check))+"/"+str(x)+"\""
            else:
                ans  = str(int(to_check))+"/"+str(x)+"\""
            print ans
            # print C,int(to_check)
            break
