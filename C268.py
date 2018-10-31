x,y = map(int,raw_input().split(' '))
ans = min(x,y)+1
print ans
curx = 0
cury = y
for i in range(ans):
    print curx,cury
    curx+=1
    cury-=1
    
