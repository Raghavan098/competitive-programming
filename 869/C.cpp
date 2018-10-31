// g++ -std=c++14

/*

Today might be the chance to grasp the chance to let your talent bloom.
May be tomorrow, the day after, or next year...
May be even when you are 30. I'm not sure if physique has anything to do with it
but if you think that it will never come, it probably never will.

- Tooru Oikawa.

*/


#include<bits/stdc++.h>

typedef unsigned long long ll;
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

const int mod = 998244353;

int a, b, c, n;

ll combi[5010];


long long binpow(long long val, long long deg, long long mod) {
    if (!deg) return 1 % mod;
    if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
    long long res = binpow(val ,deg >> 1, mod);
    return (res*res) % mod;
}
ll ncr(ll n,ll r){
    ll ans1 = combi[n];
    ll ans2 = (combi[n-r]*combi[r])%mod;
    ans2 = binpow(ans2,mod-2,mod);
    ll ans = (ans1*ans2)%mod;
    return ans;
}

int get(int a, int b){
    int ans = 0;
    int curr = 1;
    for(int i = 1; i <= min(a, b); i++){
        curr = (curr * i) % mod;
        ans = (ans + (((ncr(a, i)*ncr(b, i)) % mod) *curr) % mod) % mod;
    }
    return ans % mod;
}

int32_t main(){ _
    n = 5005;
    ll curr = 1;
    combi[0] =1;
    for(int i=1;i<=n;i++){
        combi[i] = curr;
        curr = (curr*(i+1))%mod;
    }
    cin >> a >> b >> c;
    int ab = get(a, b);
    int bc = get(b, c);
    int ca = get(c, a);
    int individual = ((ab + bc) % mod + ca) % mod;
    int ab_bc = (ab * bc) % mod;
    int bc_ca = (bc * ca) % mod;
    int ca_ab = (ca * ab) % mod;
    int ab_bc_ca = ((ab_bc) * (ca)) % mod;
    int twos = (((ab_bc + bc_ca) % mod) + ca_ab) % mod;
    int tot_ans = ((individual + twos) % mod + ab_bc_ca + 1) % mod;
    cout << tot_ans << endl;
    return 0;
}
