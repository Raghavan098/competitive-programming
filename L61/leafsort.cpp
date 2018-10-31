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
map<ll,vector<ll> > grp;

map<ll,ll> val;

ll visited[200000];
ll done = 0;
ll ans = 0;

pair<ll,ll> dfs(ll no,ll pr){
  visited[no] = 1;
  if(grp[no].size()==0){
    return mp(val[no],val[no]);
  }
  else if(grp[no].size()==1){
    return dfs(grp[no][0],no);
  }
  else{
    auto t1 = dfs(grp[no][0],no);
    auto t2 = dfs(grp[no][1],no);
    // tr(no,t1,t2);
    if(t1.fi<=t2.fi){
      if(t2.fi<t1.se){
        done = 1;
        return mp(-1,-1);
      }
      else{
        return mp(t1.fi,t2.se);
      }
    }
    else{
      ans++;
      swap(t1,t2);
      if(t2.fi<t1.se){
        done = 1;
        return mp(-1,-1);
      }
      else{
        return mp(t1.fi,t2.se);
      }
    }
  }
}

ll solve(){
  cin>>n;
  grp.clear();
  for(ll i=1;i<=n;i++){
    ll a,b;
    cin>>a>>b;
    if(a!=-1){
      grp[i].pb(a);
      grp[i].pb(b);
    }
    else{
      val[i] = b;
    }
  }
  for(ll i=1;i<=n;i++){
    visited[i] = 0;
  }
  done = 0;
  ans = 0;
  dfs(1,0);
  if(done==0)
    cout<<ans<<endl;
  else{
    cout<<-1<<endl;
  }
}

int main(){
  ll t;
  cin>>t;
  while(t--){
    solve();
  }
}
