l = map(int,raw_input().split())
l.sort()
if l[0]>1:
    print max(l[0]+(l[1]-l[0])/3+(l[2]-l[0])/3,((l[0]-1)+(l[1]-l[0]+1)/3+(l[2]-l[0]+1)/3),((l[0]-2)+(l[1]-l[0]+2)/3+(l[2]-l[0]+2)/3))
else:
    print l[1]/3+l[2]/3
