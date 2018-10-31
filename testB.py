def do(n,a,b,ac,bc,count):
    global ans
    global k
    global done
    # print n,ac,bc,count
    if ac==4 and bc==2:
        if count<ans:
            ans = count
        return
    if ac>4 or bc>2:
        return
    if n-a>=0 and done==0 and ac<4:
        do(n-a,a,b,ac+1,bc,count)
    if n-b>=0 and done==0 and bc<4:
        do(n-b,a,b,ac,bc+1,count)
    if n-a<0 and done==0 and ac<4:
        do(k-a,a,b,ac+1,bc,count+1)
    if n-b<0 and done==0 and ac<4:
        do(k-b,a,b,ac,bc+1,count+1)

n = input()
a = input()
b = input()
k = n
count = 1
done  = 0
ans = 999999999999
do(n,a,b,0,0,count)
print ans
