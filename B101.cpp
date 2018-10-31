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

ll m,n;
vector<pair<ll,ll> > inp;

const ll mod = 1e9 + 7;

bool cmp(pair<ll,ll> &a,pair<ll,ll> &b){
  return a.se<b.se;
}

ll dp[200000];
ll c[200000];

ll get_upper(ll no,ll ind){
  ll l = 0;
  ll r = ind - 1;
  ll mid,ans;
  while(l<=r){
    mid = (l+r)/2;
    if(inp[mid].se<no){
      ans = mid;
      l = mid + 1;
    }
    else{
      r = mid - 1;
    }
  }
  return ans;
}

ll get_lower(ll no,ll ind){
  ll l = 0;
  ll r = ind - 1;
  ll mid,ans = -1;
  while(l<=r){
    mid = (l+r)/2;
    if(inp[mid].se>=no){
      ans = mid;
      r = mid - 1;
    }
    else{
      l = mid + 1;
    }
  }
  // tr(ans);
  return ans;
}

int main(){ _
  cin>>n>>m;
  for(ll i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    inp.pb(mp(a,b));
  }
  inp.pb(mp(0,0));
  sort(inp.begin(),inp.end(),cmp);
  dp[0] = 1;
  c[0] = 1;
  for(ll i=1;i<=m;i++){
    auto temp = inp[i];
    ll up = get_upper(temp.se,i);
    ll low = -1;
    // tr(i,inp[i],temp,up);
    if(temp.fi>0){
      low = get_lower(temp.fi,i);
      if(low!=-1)
        dp[i] = (c[up] - c[low-1])%mod;
      else{
        dp[i] = 0;
      }
    }
    else{
      dp[i] = (c[up])%mod;
    }
    while(dp[i]<0){
      dp[i] += mod;
    }
    c[i] = (c[i-1] + dp[i])%mod;
    while(c[i]<0){
      c[i]+=mod;
    }
  }
  ll final_ans = 0;
  for(ll i=0;i<=m;i++){
    if(inp[i].se==n){
      final_ans = (final_ans + dp[i])%mod;
    }
    // cout<<dp[i]<<" "<<c[i]<<endl;
  }
  cout<<final_ans<<endl;
  return 0;
}
