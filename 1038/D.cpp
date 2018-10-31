// g++ -std=c++14

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
const int N = 5e5 + 100;
int arr[N], n;
int mf[N], mb[N], mif[N], mib[N];

int maxx(int a, int b, int c, int d){
    return max(max(a, b), max(c, d));
}

int minn(int a, int b, int c, int d){
    return min(min(a, b), min(c, d));
}

int32_t main(){ _
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    mf[0] = arr[0];
    mif[0] = arr[0];
    for(int i = 1; i < n; i++){
        int a, b, c, d;
        a = mf[i-1] - arr[i];
        b = arr[i] - mf[i-1];
        c = arr[i] - mif[i-1];
        d = mif[i-1] - arr[i];
        mf[i] = maxx(a, b, c, d);
        mif[i] = minn(a, b, c, d);
    }
    for(int i = 0 ; i < n; i ++){
        tr(mf[i], mif[i], i);
    }
    mb[n-1] = arr[n-1];
    mib[n-1] = arr[n-1];
    for(int i = n-2 ; i >= 0; i--){
        int a, b, c, d;
        a = mb[i+1] - arr[i];
        b = arr[i] - mb[i+1];
        c = arr[i] - mib[i+1];
        d = mib[i+1] - arr[i];
        mb[i] = maxx(a, b, c, d);
        mib[i] = minn(a, b, c, d);
    }
    for(int i = 0 ; i < n; i ++){
        tr(mb[i], mib[i], i);
    }
    int ans = -inf;
    for(int i = 1; i < n-1; i ++){
        tr(i, arr[i], mib[i+1], mif[i-1]);
        ans = max(ans, arr[i] - mib[i+1] - mif[i-1]);
    }
    tr(ans);
    ans = max(ans, arr[0] - mib[1]);
    ans = max(ans, arr[n-1] - mif[n-2]);
    cout << ans << endl;
}
