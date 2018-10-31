// g++ -std=c++14

/*

Today might be the chance to grasp the chance to let your talent bloom.
May be tomorrow, the day after, or next year...
May be even when you are 30. I'm not sure if physique has anything to do with it
but if you think that it will never come, it probably never will.

- Tooru Oikawa.

*/


#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define all(c) c.begin(),c.end()
#define inf 1000000000000000001

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

#define int ll

const int N = 4e5 + 100;

int n, arr[N], q, x[N], y[N], z[N], li[N], ri[N], k[N];
int a[3], b[3], c[3], m[3];

void clear_all(){
    MEMS(arr, 0);
    MEMS(x, 0);
    MEMS(y, 0);
    MEMS(z, 0);
    MEMS(li, 0);
    MEMS(ri, 0);
    MEMS(k, 0);
    MEMS(a, 0);
    MEMS(b, 0);
    MEMS(c, 0);
    MEMS(m, 0);
}

int solve(int ts){
    clear_all();
    cin >> n >> q;
    cin >> x[0] >> x[1] >> a[0] >> b[0] >> c[0] >> m[0];
    cin >> y[0] >> y[1] >> a[1] >> b[1] >> c[1] >> m[1];
    cin >> z[0] >> z[1] >> a[2] >> b[2] >> c[2] >> m[2];

    for(int i = 2; i < n; i++){
        x[i] = (a[0]*x[i-1] + b[0]*x[i-2] + c[0]) % m[0];
        y[i] = (a[1]*y[i-1] + b[1]*y[i-2] + c[1]) % m[1];
        z[i] = (a[2]*z[i-1] + b[2]*z[i-2] + c[2]) % m[2];
    }
    int tot = 0;
    for(int i = 0; i < n; i++){
        li[i] = min(x[i], y[i]) + 1;
        ri[i] = max(x[i], y[i]) + 1;
        tot += (ri[i] - li[i] + 1);
        k[i] = z[i] + 1;
    }
    // for(int i = 0; i < n; i++){
    //     cin >> li[i] >> ri[i] >> k[i];
    // }
    int ele = k[0];
    int mid, ans;
    int l = 0, r = 1e9 + 1;
    if(ele > tot){
        ans = 0;
        goto lol;
    }
    while(l <= r){
        mid = (l + r)/2;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(li[i] >= mid and ri[i] >= mid){
                cnt += (ri[i] - li[i] + 1);
            }
            else if(li[i] < mid and ri[i] >= mid){
                cnt += (ri[i] - mid + 1);
            }
        }
        if(cnt >= ele){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid  - 1;
        }
    }
    lol:
    cout << "Case #" << ts << ": " << ans << endl;
}

int32_t main(){ _
    __
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
}
