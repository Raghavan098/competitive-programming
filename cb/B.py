def solve(A):
    if(A==1 or A==2):
        return -1
    cnt = 0
    i = 1
    while(i*i<=A):
        if(A%i==0):
            cnt+=1
            if((A/i)!=i):
                cnt+=1
        i +=1
    print cnt
    if cnt == 2:
        return 1
    else:
        if A%2==0:
            return 2
        else:
            A -= 2
            cnt = 0
            i = 1
            while(i*i<=A):
                if(A%i==0):
                    cnt+=1
                    if((A/i)!=i):
                        cnt+=1
                i+=1
            if cnt==2:
                return 2
            else:
                return 1

A = input()
print solve(A)
