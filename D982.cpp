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

ll n;
ll arr[200000];
vector<pair<ll,ll> > inp;
set<ll> s;
set<ll> :: iterator l,u;
set<ll> s2;
ll len[200000],ans,mx_cnt;

int main(){
  cin>>n;
  for(ll i=0;i<n;i++){
    cin>>arr[i];
    inp.pb(mp(arr[i],i));
    ans = max(ans,arr[i]);
  }
  ans++;
  sort(inp.begin(),inp.end());
  reverse(inp.begin(),inp.end());
  s.insert(-1);
  s.insert(n);
  s2.insert(n);
  ll l1,u1;
  len[n] = 1;
  mx_cnt = 1;
  for(ll i=0;i<inp.size();i++){
    l = s.lower_bound(inp[i].se);
    u = s.upper_bound(inp[i].se);
    l--;
    l1 = *l;
    u1 = *(u);
    len[u1 - l1 - 1]--;
    if(len[u1 - l1 - 1]==0)
      s2.erase(u1 - l1 - 1);
    s.insert(inp[i].se);
    len[inp[i].se - l1 - 1]++;
    len[u1 - inp[i].se - 1]++;
    if(inp[i].se - l1 - 1!=0)
      s2.insert(inp[i].se - l1 - 1);
    if(u1 - inp[i].se - 1!=0)
      s2.insert(u1 - inp[i].se - 1);
    ll top = *s2.begin();
    if(s2.size()==1 and len[top]>mx_cnt){
      mx_cnt = len[top];
      ans = inp[i].fi;
    }
    if(s2.size()==1 and len[top]==mx_cnt and inp[i].fi<ans){
      mx_cnt = len[top];
      ans = inp[i].fi;
    }
  }
  ll a = -1;
  for(ll i=0;i<n;i++){
    if(arr[i]<ans and arr[i]+1>a){
      a = arr[i]+1;
    }
  }
  if(ans>a){
    ans = a;
  }
  cout<<ans<<endl;
}
