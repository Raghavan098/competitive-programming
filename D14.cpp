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

ll n;
map<ll,vector<ll> >grp;
vector<pair<ll,ll> > edg;
ll visited[300];
ll ans[300];

ll dfs1(ll n1,ll n2){
  visited[n1] = 1;
  vector<ll> b;
  for(auto temp:grp[n1]){
    if(temp!=n2 and visited[temp]==0){
      b.pb(dfs1(temp,n2));
    }
  }
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  if(b.size()==0){
    ans[n1] = 0;
    return 0;
  }
  else if(b.size()==1){
    ans[n1] = 1+b[0];
  }
  else{
    ans[n1] = 2 + b[0] + b[1];
  }
  return b[0]+1;
}

ll dfs(ll n1,ll n2){
  for(ll i=1;i<=n;i++){
    visited[i]= 0;
    ans[i] = 0;
  }
  dfs1(n1,n2);
  ll mx = 0;
  for(ll i=1;i<=n;i++){
    mx = max(ans[i],mx);
  }
  return mx;
}
ll final_ans;
int main(){ _
  cin>>n;
  for(ll i=0;i<n-1;i++){
    ll a,b;
    cin>>a>>b;
    edg.pb(mp(a,b));
    grp[a].pb(b);
    grp[b].pb(a);
  }
  for(ll i=0;i<n-1;i++){
    auto temp = edg[i];
    ll n1 = edg[i].fi;
    ll n2 = edg[i].se;
    ll p1 = dfs(n1,n2);
    ll p2 = dfs(n2,n1);
    // tr(p1,p2,p1*p2);
    final_ans = max(final_ans,p1*p2);
  }
  cout<<final_ans<<endl;
  return 0;
}
