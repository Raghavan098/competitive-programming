// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%lld",&x)
#define sd2(x,y) scanf("%lld%lld",&x,&y)
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

const ll N = 55;
ll n,m,sz,x;
ll ans[N];
ll sum[N];
ll suf[N];
ll pre[N];
ll arr[300300];

int main(){
  sd2(n,m);
  for(ll i=1;i<=n;i++){
    sd(sz);
    ans[i] = pre[i] = -1e9;
    while(sz--){
      sd(x);
      sum[i] += x;
      pre[i] = max(pre[i],sum[i]);
      suf[i] = max(0LL,suf[i]) + x;
      ans[i] = max(ans[i],suf[i]);
    }
  }
  for(ll i=0;i<m;i++){
    sd(arr[i]);
  }
  // for(ll i=1;i<=n;i++){
  //   tr(i,sum[i],pre[i],suf[i],ans[i]);
  // }
  ll c[300300];
  c[0] = sum[arr[0]];
  multiset<ll> s;
  ll mx = ans[arr[0]];
  for(ll i=1;i<m;i++){
    s.insert(c[i-1] + pre[arr[i]]);
    c[i] = c[i-1] + sum[arr[i]];
    mx = max(mx,ans[arr[i]]);
  }
  for(ll i=0;i<m-1;i++){
    ll temp = *(s.rbegin());
    temp = temp - c[i] + suf[arr[i]];
    s.erase(s.find(c[i] + pre[arr[i+1]]));
    mx = max(mx,temp);
  }
  printf("%lld\n",mx);
}
