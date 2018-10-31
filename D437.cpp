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

const ll N = 100100;
ll parent[N];
ll size[N];

void make_set(ll x){
  parent[x] = x;
  size[x] = 1;
}

ll find_set(ll v){
  if(v==parent[v]){
    return v;
  }
  return parent[v] =find_set(parent[v]);
}

void union_sets(ll a,ll b){
  a = find_set(a);
  b = find_set(b);
  if(a!=b){
    if(size[a]<size[b]){
      swap(a,b);
    }
    parent[b] = a;
    size[a] += size[b];
  }
}

ll n,m;
map<ll,vector<ll> >grp;
vector<pair<ll,ll> > arr;
ll tot = 0;

int main(){
  cin>>n>>m;
  arr.resize(n);
  for(ll i=1;i<=n;i++){
    cin>>arr[i-1].fi;
    arr[i-1].se = i;
  }
  for(ll i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    grp[a].pb(b);
    grp[b].pb(a);
  }
  sort(arr.begin(),arr.end(),greater<pair<ll,ll> >());
  ll total = 0;
  for(ll i=0;i<n;i++){
    ll x = arr[i].se;
    make_set(x);
    ll siz = 0;
    ll t =1;
    set<ll> done;
    for(auto no:grp[x]){
      ll temp = find_set(no);
      if(temp!=0 and done.find(temp)==done.end()){
        siz += size[temp]*t;
        t+=size[temp];
        done.insert(temp);
        union_sets(temp,x);
      }
    }
    total += (arr[i].fi)*(siz);

  }
  ll tq = (n*(n-1))/2;
  lld ans = (total*1.00)/(tq);
  printf("%0.15Lf\n",ans);
  return 0;
}
