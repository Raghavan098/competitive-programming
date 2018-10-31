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
const int N = 3e5 + 7;
int n;
int a[N], b[N], ca[N], cb[N];
int bb[N], bc[N];

pair<int, int> mer(int a, int b, int c, int d){
    if(a == -1){
        return mp(-1, -1);
    }
    if(a > c){
        swap(a, c);
        swap(b, d);
    }
    if(b < c){
        return mp(-1, -1);
    }
    else{
        if(a <= c and b >= c){
            if(b >= d){
                return mp(c, d);
            }
            else{
                return mp(c, b);
            }
        }
    }
}



int32_t main(){ _
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    ca[0] = a[0];
    cb[0] = b[0];
    for(int i = 1; i < n; i++){
        auto ans = mer(ca[i-1], cb[i-1], a[i], b[i]);
        ca[i] = ans.fi;
        cb[i] = ans.se;
    }
    bb[n-1] = a[n-1];
    bc[n-1] = b[n-1];
    for(int i = n-2; i >= 0; i--){
        auto ans = mer(bb[i+1], bc[i+1], a[i], b[i]);
        bb[i] = ans.fi;
        bc[i] = ans.se;
    }
    int mx = -1;
    for(int i = 1; i < n-1; i ++){
        auto ans = mer(ca[i-1], cb[i-1], bb[i+1], bc[i+1]);
        mx = max(mx, ans.se - ans.fi);
    }
    mx = max(mx, cb[n-2] - ca[n-2]);
    mx = max(mx, bc[1] - bb[1]);
    cout << mx << endl;
    return 0;
}
