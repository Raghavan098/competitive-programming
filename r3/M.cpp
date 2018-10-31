// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%lld",&x)
#define sd2(x,y) scanf("%lld%lld",&x,&y)
#define sd3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
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



ll n, l;
vector<vector<ll>> adj;

ll timer;
vector<ll> tin, tout;
vector<vector<ll>> up;

void dfs(ll v, ll p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (ll i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (ll u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancetor(ll u, ll v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v)
{
    if (is_ancetor(u, v))
        return u;
    if (is_ancetor(v, u))
        return v;
    for (ll i = l; i >= 0; --i) {
        if (!is_ancetor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(ll root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<ll>(l + 1));
    dfs(root, root);
}

unordered_map<ll, vector<pair<ll,ll> > >grp1;
unordered_map<ll, vector<pair<ll,ll> > >grp2;

ll A[200000];
ll B[200000];
ll visited[200000];

void dfs1(ll no){
  visited[no] = 1;
  for(auto i:grp1[no]){
    if(visited[i.fi]==0){
      A[i.fi] = A[no] + i.se;
      dfs1(i.fi);
    }
  }
}

void dfs2(ll no){
  visited[no] = 1;
  for(auto i:grp2[no]){
    if(visited[i.fi]==0){
      B[i.fi] = B[no] + i.se;
      dfs2(i.fi);
    }
  }
}

void clear_all(){
  adj.clear();
  grp2.clear();
  grp1.clear();
  for(ll i=0;i<n;i++){
    visited[i] = 0;
    A[i] = 0;
    B[i] = 0;
  }
  tin.clear();
  tout.clear();
  up.clear();

}
ll a,b,c,d;
ll solve(){
  sd(n);
  clear_all();
  adj.resize(n+1);
  ll tot_sum = 0;
  for(ll i=1;i<n;i++){
    sd3(a,b,c);
    sd(d);
    tot_sum+=c;
    tot_sum+=d;
    a--;
    b--;
    adj[a].pb(b);
    adj[b].pb(a);
    grp1[a].pb(mp(b,c));
    grp1[b].pb(mp(a,d));
    grp2[a].pb(mp(b,d));
    grp2[b].pb(mp(a,c));
  }
//   cout<<n<<endl;
  preprocess(0);
  dfs1(0);
  for(ll i=0;i<n;i++){
    visited[i] = 0;
  }
  dfs2(0);
  ll mm;
  sd(mm);
  for(ll i=0;i<mm;i++){
    ll aa,bb;
    sd2(aa,bb);
    aa--;
    bb--;
    ll l = lca(aa,bb);
    // tr(l,tot_sum);
    printf("%lld\n",tot_sum -(A[aa] - A[l]) - (B[bb] - B[l]));
  }
  return 0;
}

int main(){
  ll t;
  sd(t);
  while(t--){
    solve();
  }
}
