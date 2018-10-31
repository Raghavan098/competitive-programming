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

ll n,m1,k;
map<ll,vector<pair<ll,ll> > > grp;
map<ll,vector<ll> >grp2;
ll c[200000],k2[1000];
ll pre[200000];
ll m[1000];
ll visited[200000];
ll graph[600][600];
ll shortest_path[600][600];

void floyd_warshall(){
  for(ll i=1;i<=k;i++){
    for(ll j=1;j<=k;j++){
      shortest_path[i][j] = graph[i][j];
    }
  }
  for(ll k1=1;k1<=k;k1++){
    for(ll i=1;i<=k;i++){
      for(ll j=1;j<=k;j++){
        if(shortest_path[i][k1]+shortest_path[k1][j]<shortest_path[i][j]){
          shortest_path[i][j] = shortest_path[i][k1]+shortest_path[k1][j];
        }
      }
    }
  }
}

void dfs(ll no,ll cop){
  visited[no] = 1;
  pre[no] = cop;
  m[c[no]] = cop;
  for(auto temp:grp2[no]){
    if(visited[temp]==0){
      dfs(temp,cop);
    }
  }
}

int main(){
  cin>>n>>m1>>k;
  for(ll i=0;i<k;i++){
    cin>>k2[i];
  }
  ll curr = 0;
  for(ll i=0;i<k;i++){
    for(ll j = 0;j<k2[i];j++){
      c[j + curr +1] = i+1;
    }
    curr += (k2[i]);
  }
  for(ll i=0;i<m1;i++){
    ll a,b,c;
    cin>>a>>b>>c;
    grp[a].pb(mp(b,c));
    grp[b].pb(mp(a,c));
    if(c==0){
      grp2[a].pb(b);
      grp2[b].pb(a);
    }
  }
  for(ll i=1;i<=n;i++){
    if(visited[i]==0){
      m[c[i]] = i;
      dfs(i,i);
    }
  }

  for(ll i=1;i<=n;i++){
    ll x,y,z;
    x = c[i];
    y = m[c[i]];
    z = pre[i];
    if(y!=z){
      cout<<"No\n";
      return 0;
    }
  }
  cout<<"Yes\n";
  for(ll i = 0;i<=k;i++){
    for(ll j = 0;j<=k;j++){
      graph[i][j] = inf;
    }
    graph[i][i] =  0;
  }
  for(ll i=1;i<=n;i++){
    for(auto temp:grp[i]){
      if(graph[c[i]][c[temp.fi]]>temp.se){
        graph[c[i]][c[temp.fi]] = temp.se;
      }
    }
  }
  // for(ll i=1;i<=k;i++){
  //   for(ll j = 1;j<=k;j++){
  //     cout<<graph[i][j]<<" ";
  //   }cout<<endl;
  // }
  floyd_warshall();
  for(ll i=1;i<=k;i++){
    for(ll j=1;j<=k;j++){
      if(shortest_path[i][j]!=inf){
        cout<<shortest_path[i][j]<<" ";
      }
      else{
        cout<<-1<<" ";
      }
    }cout<<endl;
  }

  return 0;
}
