#include <bits/stdc++.h>

typedef long long int lli;
using namespace std;

lli bs(lli l, lli r, lli key, lli a[])
{
    lli ret = 1e18,mid;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(a[mid] >= key)
        {
            ret = min(ret,mid);
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return ret;
}

int main()
{
    for(int test = 21; test <= 29; test++){
        string in = "input" + to_string(test) + ".txt";
        string out = "output" + to_string(test) + ".txt";
        freopen(in.c_str(),"r",stdin);
        freopen(out.c_str(),"w",stdout);
        lli n,q,k,ans;
        cin >> n >> q;
        lli a[n+1];
        a[0] = 0;
        for(int i = 1; i<=n; i++)
        {
            cin >> a[i];
        }
        for(int i = 1; i<=n; i++)
        {
            a[i] += a[i-1];
        }
        for(int i = 0; i<q; i++)
        {
            cin >> k;
            ans = bs(0,n,k,a);
            if(ans == 1e18)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << ans << endl;
            }
        }
    }
}
