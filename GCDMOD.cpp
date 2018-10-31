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

const ll M = 1e9 + 7;

ll gcd(ll n1, ll n2)
{
    if (n2 != 0)
       return gcd(n2, n1%n2);
    else
       return n1;
}

ll mult(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}

ll pow1(ll a, ll p, ll mod) {
	if (!p) return 1;
	ll ret = pow1(a, p >> 1, mod);
    ret %= mod;
	ret = mult(ret, ret, mod) % mod;
	if (p & 1LL) ret = mult(ret, a, mod) % mod;
	return ret % mod;
}

ll solve(){
    ll a, b, n;
    cin >> a >> b >> n;
    ll mod = (a - b);
    if(mod == 1){
        cout << 1 << endl;
        return 0;
    }
    if(mod == 0){
        ll t1 = pow1(a, n, M);
        ll t2 = pow1(b, n, M);
        cout << (t1 + t2)%M << endl;
        return 0;
    }
    ll t1 = pow1(a, n, mod);
    ll t2 = pow1(b, n, mod);
    ll t3 = (t1 + t2)%mod;
    cout << gcd(mod, t3) << endl;
    return 0;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
