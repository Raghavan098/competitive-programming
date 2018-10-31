import math

def get_ans(no):
    ans = 0
    root = int(math.sqrt(no))
    for i in range(1,root+1):
        st = root+1
        end = no/i
        if(st<=end):
            tot = end - st +1
            ans+=i*((no/i)) + (tot*(st+end))/2
        else:
            ans+=i*((no/i));
    return ans

a,b = map(int,raw_input().split())
print get_ans(b) - get_ans(a-1)
