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

const ll mod = 1000000007;

ll d,n;
ll arr[3000];
map<ll,vector<ll> > grp;
map<ll,vector<ll> > tmp;
ll visited[3000];

void dfs(ll no,ll tt){
  visited[no] = 1;
  // tr(no);
  for(auto c:grp[no]){
    if(arr[c]>=arr[tt] and arr[c]<= arr[tt] + d and visited[c]==0){
      if(arr[c]==arr[tt] and tt>c)continue;
      tmp[no].pb(c);
      tmp[c].pb(no);
      dfs(c,tt);
    }
  }
}

ll dfs2(ll no){
  visited[no] = 1;
  ll temp_ans = 1;
  for(auto c: tmp[no]){
    if(visited[c]==0){
      temp_ans = (temp_ans*(1 + dfs2(c)))%mod;
    }
  }
  // tr(no,temp_ans);
  return temp_ans;
}

int main(){
  cin>>d>>n;
  for(ll i=1;i<=n;i++){
    cin>>arr[i];
  }
  ll a,b;
  for(ll i=1;i<n;i++){
    cin>>a>>b;
    grp[a].pb(b);
    grp[b].pb(a);
  }
  ll tot_ans = 0;
  for(ll i=1;i<=n;i++){
    tmp.clear();
    MEMS(visited,0);
    dfs(i,i);
    MEMS(visited,0);
    ll hello = dfs2(i);
    tot_ans = (tot_ans + hello)%mod;
  }
  cout<<tot_ans<<endl;
  return 0;
}
