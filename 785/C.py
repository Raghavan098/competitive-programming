n,m = map(int,raw_input().split())
if m>=n:
    print n
else:
    s = (n - (m+1))
    if(s<=0):
        print m+1
    else:
        l = m+2
        r = n
        ans = n
        while(l<=r):
            mid = (l+r)/2
            eat = ((m + 2 + mid)*(mid - (m+1)))/2
            av = s + m*(mid - (m+1))
            if (av<=eat):
                ans = mid
                r = mid - 1
            else:
                l = mid + 1

        print ans

        
