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

vector<ll> get(vector<ll>a,vector<ll> b,ll n){
  vector<ll> ans;
  ans.resize(n);
  for(ll i=0;i<n;i++){
    ans[i] = b[a[i]-1];
  }
  return ans;
}

vector<ll> inv_get(vector<ll> a,vector<ll> b,ll n){
  vector<ll> ans;
  ans.resize(n);
  map<ll,ll> mp;
  for(ll i=0;i<n;i++){
    mp[a[i]] = i;
  }
  for(ll i=0;i<n;i++){
    // tr(i,mp[a[i]],b[mp[a[i]]]);
    ans[i] = b[mp[i+1]];
  }
  return ans;
}

ll solve(){
  ll n,m;
  cin>>n>>m;
  vector<vector<ll> > v;
  for(ll i=0;i<n;i++){
    vector<ll> temp;
    for(ll j=0;j<m;j++){
      ll kk;
      cin>>kk;
      temp.pb(kk);
    }
    v.pb(temp);
  }
  vector<vector<ll> > cu;
  cu.pb(v[0]);
  vector<ll> temp = v[0];
  for(ll i = 1;i<n;i++){
    temp = get(temp,v[i],m);
    cu.pb(temp);
  }
  for(auto v1: cu){
    cout<<v1<<endl;
  }
  ll q;
  cin>>q;
  while(q--){
    ll a,b;
    cin>>a>>b;
    a--;
    b--;
    if(a==0){
      ll ans = 0;
      // tr(cu[b]);
      for(ll i=0;i<m;i++){
        ans+=((i+1)*cu[b][i]);
      }
      cout<<ans<<endl;
    }
    else{
      vector<ll> xt = inv_get(cu[a-1],cu[b],m);
      ll ans = 0;
      for(ll i=0;i<m;i++){
        ans+=((i+1)*xt[i]);
      }
      cout<<ans<<endl;
    }
  }
}

int main(){
  ll t;
  cin>>t;
  while(t--){
    solve();
  }
}
