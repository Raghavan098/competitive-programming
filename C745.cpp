// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

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

set<ll> gvt;
ll n,m,k,x,y,visited[2000],ans,maxgt,ct,yes,siz;
vector<ll> nodes;
map<ll,vector<ll> > grp;
ll indp;

void dfs(ll no){
  nodes.pb(no);
  visited[no] =1;
  ll temp;
  for(ll i=0;i<grp[no].size();i++){
    temp = grp[no][i];
    if(visited[temp]==0){
      dfs(temp);
    }
  }
}
int main(){
  cin>>n>>m>>k;
  for(ll i=0;i<k;i++){
    cin>>x;
    gvt.insert(x);
  }
  for(ll i=1;i<=m;i++){
    cin>>x>>y;
    grp[x].pb(y);
    grp[y].pb(x);
  }
  ans =0;
  maxgt = 0;
  for(ll i=1;i<=n;i++){
    if(visited[i]==0){
      nodes.clear();
      dfs(i);
      ct = 0;
      yes = 0;
      for(ll j=0;j<nodes.size();j++){
        if(gvt.find(nodes[j])!=gvt.end()){
          yes = 1;
        }
        ct+=grp[nodes[j]].size();
      }
      siz = nodes.size();
      ans+=((siz*(siz-1)) - ct)/2;
      if(yes==1){
        if(siz>maxgt){
          maxgt = siz;
        }
      }
      else{
        ans+=(indp)*siz;
        indp+=siz;
      }
    }
  }
  ans+=(indp)*maxgt;
  cout<<ans<<endl;
  return 0;
}
