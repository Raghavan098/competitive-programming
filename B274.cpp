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

ll n,a,b;
map<ll,vector<ll> > grp;
ll visited[200000];
ll ans[200000];
ll moves[200000];
ll arr[200000];

pair<ll,ll> dfs(ll no){
  visited[no] = 1;
  pair<ll,ll > t,k;
  t.fi = 0;
  t.se = 0;
  for(auto temp:grp[no]){
    if(visited[temp]==0){
      k = dfs(temp);
      t.fi = max(t.fi,k.fi);
      t.se = max(t.se,k.se);
    }
  }
  ans[no] = arr[no] + t.fi - t.se;
  if(ans[no]<0){
    t.fi += abs(ans[no]);
  }
  else{
    t.se += ans[no];
  }
  return t;
}

int main(){
  cin>>n;
  for(ll i=0;i<n-1;i++){
    cin>>a>>b;
    grp[a].pb(b);
    grp[b].pb(a);
  }
  for(ll i=1;i<=n;i++){
    cin>>arr[i];
  }
  pair<ll,ll> ans;
  ans = dfs(1);
  cout<<ans.fi + ans.se<<endl;
  return 0;
}
