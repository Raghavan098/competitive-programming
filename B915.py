n,pos,l,r = map(int,raw_input().split())
if pos>=l and pos<=r:
    fir = r - pos
    sec = pos - l
    # print fir,sec
    if fir<sec:
        ans = 0
        if l!=1:
            ans+=sec
            ans+=1
        if r!=n:
            ans+=fir
            if l!=1:
                ans+=fir
            ans+=1
        print ans
    else:
        ans = 0
        if r!=n:
            ans+=fir
            ans+=1
        if l!=1:
            ans+=sec
            if r!=n:
                ans+=sec
            ans+=1
        print ans
elif pos<l:
    ans = 0
    if l!=1:
        ans += l-pos+1
    if r!=n:
        ans+=(r-l)+1
    print ans
else:
    ans = 0
    if r!=n:
        ans += pos-r+1
    if l!=1:
        ans+=(r - l)+1
    print ans
