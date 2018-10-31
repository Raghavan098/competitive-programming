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

ll m,k;
vector<pair<pair<ll,ll> ,ll> > inp;
vector<ll> money;
ll sum_mon[200000];

void solve(){
  cin>>m>>k;
  inp.clear();
  money.clear();
  for(int i=0;i<=m+1;i++){
    sum_mon[i] = 0;
  }
  inp.pb(mp(mp(0,0),0));
  money.pb(0);
  for(ll i=0;i<m;i++){
    ll a,b,c;
    cin>>a>>b>>c;
    inp.pb(mp(mp(a,b),c));
    money.pb(c);
  }
  sort(inp.begin(),inp.end());
  for(ll i=1;i<=m;i++){
    if(i==1){
      sum_mon[i] = inp[i].se*((inp[i].fi).se - (inp[i].fi).fi + 1);
    }
    else{
      sum_mon[i] = sum_mon[i-1] + inp[i].se*((inp[i].fi).se - (inp[i].fi).fi + 1);
    }
  }
  ll final_ans = 0;
  for(ll i=1;i<=m;i++){
    ll st = (inp[i].fi).fi;
    ll end = min(ll(1e9),(st + k -1));
    ll l = i;
    ll r = m;
    ll mid,ans;
    while(l<=r){
      mid = (l+r)/2;
      if((inp[mid].fi).fi<=end){
        ans = mid;
        l = mid + 1;
      }
      else{
        r = mid - 1;
      }
    }
    ll pre = sum_mon[ans-1] - sum_mon[i-1];
    pre += (inp[ans].se)*(min(end,inp[ans].fi.se) - inp[ans].fi.fi + 1);
    final_ans = max(final_ans,pre);
  }
  ll final_ans2 = 0;
  for(ll i=1;i<=m;i++){
    ll end = (inp[i].fi).se;
    ll st = max(ll(1),(end - k  +1));
    ll r = i;
    ll l = 1;
    ll mid,ans;
    while(l<=r){
      mid = (l+r)/2;
      if((inp[mid].fi).se>=st){
        ans = mid;
        r = mid - 1;
      }
      else{
        l = mid + 1;
      }
    }
    ll pre;
    pre = sum_mon[i] - sum_mon[ans];
    pre += inp[ans].se*(inp[ans].fi.se - max(st,inp[ans].fi.fi) + 1);
    final_ans2 = max(final_ans2,pre);
  }
  cout<<max(final_ans2,final_ans)<<endl;
}

int main(){ _
  ll t;
  cin>>t;
  while(t--){
    solve();
  }
}
