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

const ll N = 5050;

ll n,w,h;
vector<pair<ll,ll> > v;

map<pair<ll,ll>,ll> ind;
ll ans[N];
ll pre[N];

int main(){ _
  cin>>n>>w>>h;
  for(ll i=0;i<n;i++){
    ll a,b;
    cin>>a>>b;
    v.pb(mp(a,b));
    ind[mp(a,b)] = i;
  }
  sort(v.begin(),v.end());
  for(ll i=0;i<n;i++){
    ans[i] = 1;
    pre[i] = -1;
    auto temp = v[i];
    if(!(temp.fi>w and temp.se>h)){
      ans[i] = 0;
      continue;
    }
    for(ll j =i-1;j>=0;j--){
      if(v[j].fi<temp.fi and v[j].se<temp.se){
        if(ans[j]+1>ans[i]){
          ans[i] = ans[j] + 1;
          pre[i] = j;
        }
      }
    }
  }
  ll mx = 0;
  ll mx_ind;
  for(ll i=0;i<n;i++){
    if(ans[i]>mx){
      mx = ans[i];
      mx_ind = i;
    }
  }
  // tr(mx_ind);
  cout<<mx<<endl;
  if(mx==0)return 0;
  vector<ll> ans;
  while(mx_ind!=-1){
    auto temp = ind[v[mx_ind]];
    ans.pb(temp+1);
    mx_ind = pre[mx_ind];
  }
  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;
  return 0;
}
