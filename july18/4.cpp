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

const ll mod = 1e9+7;
ll combi[1000006];

long long binpow(long long val, long long deg, long long mod) {
        if (!deg) return 1 % mod;
        if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
        long long res = binpow(val ,deg >> 1, mod);
        return (res*res) % mod;
}
ll ncr(ll n,ll r){
  ll ans1 = combi[n];
  ll ans2 = (combi[n-r]*combi[r])%1000000007;
  ans2 = binpow(ans2,1000000007-2,1000000007);
  ll ans = (ans1*ans2)%1000000007;
  return ans;
}


ll solve(){
  ll n,k;
  ll arr[5050];
  cin>>n>>k;
  k-=2;
  for(ll i=0;i<n;i++){
    cin>>arr[i];
  }
  ll get[5050];
  ll ans[5050];
  MEMS(ans,0);
  ll ele,temp;
  for(ll i=k-1;i<=n-1;i++){
    get[i] = ncr(i,k-1);
  }
  for(ll i=0;i<n;i++){
    for(ll j=i+k+1;j<n;j++){
      ele = j-i-1;
      temp = get[ele-1];
      ans[i+1] = (ans[i+1] + temp)%mod;
      ans[j] =(ans[j] - temp)%mod;
    }
  }
  for(ll i=1;i<n;i++){
    ans[i] = (ans[i-1] + ans[i])%mod;
    while(ans[i]<0){
      ans[i] += mod;
    }
  }
  ll tot = 1;
  for(ll i=0;i<n;i++){
    tot = (tot * binpow(arr[i],ans[i],mod))%mod;
  }
  cout<<tot<<endl;
}

int main(){
  ll n;
  n = 5050;
  ll curr = 1;
  combi[0] =1;
  for(ll i=1;i<=n;i++){
    combi[i] = curr;
    curr = (curr*(i+1))%1000000007;
  }
  ll t;
  cin>>t;
  for(ll i=0;i<t;i++){
    solve();
  }
}
