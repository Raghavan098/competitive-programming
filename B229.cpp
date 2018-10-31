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

ll n,m;
map<ll,vector<pair<ll,ll> > > grp;
map<ll,ll> ks[200000];
ll d[200000];


void dijistra(ll s){
  fill(d+1,d+n+1,inf);
  set<pair<ll,ll> > q;
  if(ks[1].find(0)!=ks[1].end()){
    d[s] = ks[1][0];
  }
  else{

    d[s] = 0;
  }
  q.insert(mp(d[s],s));
  while(!q.empty()){
    ll v = (*q.begin()).se;
    ll v_d = (*q.begin()).fi;
    q.erase(q.begin());
    // tr(v,v_d);
    if(v==n){
      break;
    }
    for(auto t:grp[v]){
      ll to = t.fi;
      ll weight = t.se;
      ll get_out = v_d + weight;
      if(ks[to].find(get_out)!=ks[to].end()){
        get_out = ks[to][get_out];
      }
      // tr(to,weight,get_out,d[to]);
      if(get_out<d[to]){
        d[to] = get_out;
        q.insert(mp(get_out,to));
      }
    }
  }
}

int main(){
  cin>>n>>m;
  for(ll i=0;i<m;i++){
    ll a,b,c;
    cin>>a>>b>>c;
    grp[a].pb(mp(b,c));
    grp[b].pb(mp(a,c));
  }
  vector<ll> v;
  ll temp;
  for(ll i=1;i<=n;i++){
    ll k;
    cin>>k;
    v.clear();
    for(ll j=0;j<k;j++){
      cin>>temp;
      v.pb(temp);
    }
    if(i==n)continue;
    for(ll j=k-1;j>=0;j--){
      if(j==k-1 || v[j]+1!=v[j+1]){
        ks[i][v[j]] = v[j] + 1;
      }
      else{
        ks[i][v[j]] = ks[i][v[j+1]];
      }
    }
  }
  dijistra(1);
  // for(int i=1;i<=n;i++){
  //   cout<<d[i]<<" ";
  // }cout<<endl;
  if(d[n]==inf){
    cout<<-1<<endl;
  }
  else{
    cout<<d[n]<<endl;
  }
}
