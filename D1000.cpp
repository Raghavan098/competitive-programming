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


ll combi[1000006];

const ll mod = 998244353;

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

const ll N = 100009;
ll n;
ll arr[N];
ll dp[N];


int main(){
  cin>>n;
  ll curr = 1;
  combi[0] =1;
  for(ll i=1;i<=10000;i++){
    combi[i] = curr;
    curr = (curr*(i+1))%mod;
  }
  for(ll i=0;i<n;i++){
    cin>>arr[i];
  }
  dp[n] = 1;
  for(ll i=n-1;i>=0;i--){
    if(arr[i]<=0)continue;
    for(ll j = i + arr[i] +1;j<=n;j++){
      dp[i] = (dp[i] + (dp[j]*ncr(j - i - 1,arr[i]))%mod)%mod;
    }
  }
  ll final_ans = 0;
  for(ll i=0;i<n;i++){
    final_ans = (final_ans + dp[i])%mod;
  }
  cout<<final_ans<<endl;
  return 0;
}
