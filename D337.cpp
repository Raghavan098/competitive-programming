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
#define inf 999999

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

int arr[200000];
map<int,vector<int> > grp;
int dpDown[200000];
int dpUp[200000];
int n,m,k;
int visited[200000];
void dfs1(int no,int parent){
  visited[no] = 1;
  dpDown[no] = -inf;
  if(arr[no]==1){
    dpDown[no] = 0;
  }
  vector<int>  chd;
  for(auto i:grp[no]){
    if(visited[i]==0){
      dfs1(i,no);
      chd.pb(i);
    }
  }
  int mx_dn = -inf;
  int chk = 0;
  for(auto i:chd){
    mx_dn = max(mx_dn,dpDown[i]);
  }
  dpDown[no] = max(mx_dn + 1,dpDown[no]);
}

void dfs2(int no,int parent){
  visited[no] = 1;
  int m1= 0;
  if(dpUp[no]>0)
    m1 = dpUp[no]+1;
  if(arr[no]==1){
    m1 = max(m1,1);
  }
  multiset<int> s;
  vector<int> chd;
  for(auto i: grp[no]){
    if(visited[i]==0){
      s.insert(dpDown[i]);
      chd.pb(i);
    }
  }
  // tr(no);
  int m2 = 0;
  // for(auto i: s){
  //   tr(i);
  // }
  for(auto i:chd){
    s.erase(s.find(dpDown[i]));
    if(s.size()>0)
      m2 = *(s.rbegin()) + 2;
    else{
      m2 = 0;
    }
    dpUp[i] = max(m1,m2);
    dfs2(i,no);
    s.insert(dpDown[i]);
  }
}

int main(){
  cin>>n>>m>>k;
  for(int i=0;i<m;i++){
    int temp;
    cin>>temp;
    arr[temp] = 1;
  }
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    grp[a].pb(b);
    grp[b].pb(a);
  }
  dfs1(1,0);
  MEMS(visited,0);
  dfs2(1,0);
  int ct = 0;
  for(int i=1;i<=n;i++){
    // tr(i,dpUp[i],dpDown[i]);
    if(max(dpUp[i],dpDown[i])<=k){
      ct++;
      // tr(i);
    }
  }
  cout<<ct<<endl;
  return 0;
}
