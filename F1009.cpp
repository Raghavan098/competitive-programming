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

const int maxn = 1000100;
vector<int> grp[maxn];
int n;
int sz[maxn];
int ans[maxn];
bool big[maxn];
int cnt[maxn];
int height[maxn];
int tree[4*maxn];
void preprocess(int v, int p, int h){
  sz[v] = 1;
  height[v] = h;
  for(auto u: grp[v]){
    if(u!=p){
      preprocess(u,v,h+1);
      sz[v] += sz[u];
    }
  }
}

void udp(int idx, int l, int r, int in, int val){
  if(l==r){
    tree[idx] += val;
    return;
  }
  int mid = (l + r)/2;
  if(in <= mid){
    udp(2*idx,l,mid,in,val);
  }
  else{
    udp(2*idx + 1,mid + 1,r,in,val);
  }
  if(tree[idx*2]>=tree[2*idx + 1]){
    tree[idx] = tree[idx*2];
  }
  else{
    tree[idx] = tree[idx*2 + 1];
  }
}

int q(int idx,int l,int r){
  if(l==r){
    return l;
  }
  if(tree[2*idx]>=tree[2*idx + 1]){
    return q(2*idx,l,(l+r)/2);
  }
  else{
    return q(2*idx + 1,((l+r)/2 + 1),r);
  }
}

void add(int v, int p, int x){
  udp(1,1,n,height[v],x);
  for(auto u: grp[v]){
    if(u != p and big[u]==false){
      add(u,v,x);
    }
  }
}

void dfs(int v, int p, bool keep){
  int mx = -1;
  int bigChild = -1;
  for(auto u: grp[v]){
    if(u!=p and sz[u]>mx){
      mx = sz[u];
      bigChild = u;
    }
  }
  for(auto u: grp[v]){
    if(u!=p and u!=bigChild){
      dfs(u,v,0);
    }
  }
  if(bigChild!=-1){
    dfs(bigChild,v,1);
    big[bigChild] = true;
  }
  add(v,p,1);
  ans[v] = q(1,1,n);
  if(bigChild != -1){
    big[bigChild] = 0;
  }
  if(keep == 0){
    add(v,p,-1);
  }
}

int main(){
  sd(n);
  for(int i=0;i<n-1;i++){
    int a,b;
    sd2(a,b);
    grp[a].pb(b);
    grp[b].pb(a);
  }
  preprocess(1,0,1);
  dfs(1,0,1);
  for(int i=1;i<=n;i++){
    printf("%d\n",ans[i] - height[i]);
  }
  return 0;
}
