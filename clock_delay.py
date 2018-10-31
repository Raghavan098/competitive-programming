q = input()
while(q>0):
    q-=1
    h1,m1,h2,m2 = map(int,raw_input().split())
    k = input()
    h1+=k
    mins = (h1 - h2)*60
    if m1 == 0:
        m1 = 60
    if m2== 0:
        m2 = 60

    # print mins
    if m2>m1:
        mins -= (m2-m1)%60
    else:
        mins += (m1 - m2)%60

    print mins
