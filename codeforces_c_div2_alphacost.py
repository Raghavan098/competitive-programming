def ret_no(x,no):
    for i in range(len(x)-1):
        if x[i]<=no and x[i+1]>no:
            return (i+2,x[i])
x=[1,3,6,10,15]
for i in range(7,500):
    if i%2==0:
        p=i/2
        q=i/2
    else:
        p=i/2
        q=i/2+1
    #print p*q+x[p-2]+x[q-2],i,p,q,x[p-2],x[q-2]
    x.append(p*q+x[p-2]+x[q-2])
alpha = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
crralpha = 0
n = input()
string=""
if n==0:
    print "a"
else:
    while(n):
        temp = ret_no(x,n)
        string+=(alpha[crralpha]*temp[0])
        n-=temp[1]
        crralpha+=1
    print string
