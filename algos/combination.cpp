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



const int N = 4e5;
const int MOD = 1e9 + 7;

int fac[N + 10], ifac[N + 10];

int power(int x, int t){
    int ans = 1;
    while(t > 0) {
        if(t & 1) ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        t >>= 1;
    }
    return ans;
}

void init_fac(){
    fac[0] = 1;
    for(int i = 1; i < N; i++){
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    ifac[N - 1] = power(fac[N - 1], MOD - 2);
    for(int i = N - 1; i >= 1; i--){
        ifac[i - 1] = (ifac[i] * i) % MOD;
    }
}

int C(int n, int m)
{
	if(n < m) return 0;
	return fac[n] * (1LL * ifac[m] * ifac[n - m] % MOD) % MOD;
}

int s(int n, int k){
    if(n == 0) return (k == 0);
    if(k == 0) return (n == 0);
    int ans = 0;
    int sg[2] = {1, MOD - 1};
    for(int i = 0; i <= k; i++){
        ans = (ans + (sg[i & 1LL] * ((C(k, i) * power(k - i, n)) % MOD)) % MOD) % MOD;
    }
    ans = (ans * ifac[k]) % MOD;
    return ans;
}


int32_t main(){ _
    init_fac();
}
