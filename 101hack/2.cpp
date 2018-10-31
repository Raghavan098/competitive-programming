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

ll n;
ll a[200000],b[200000];

pair<ll,ll> arr[200000];

pair<ll,ll> get(pair<ll,ll> x,pair<ll,ll> y){
  if(x.fi>y.fi){
    swap(x,y);
  }
  if(x.se<y.fi){
    return mp(-1,-1);
  }
  else
    return mp(max(y.fi,x.fi),min(x.se,y.se));
}

bool in(ll no,pair<ll,ll> ii){
  return (no>=ii.fi and no<=ii.se);
}

int main(){
  cin>>n;
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  for(ll i=0;i<n;i++){
    cin>>b[i];
    arr[i] = mp(a[i],b[i]);
  }
  pair<ll,ll> curr = mp(a[0],b[0]);
  pair<ll,ll> prev;
  ll i = 1;
  vector<ll> ans;
  while(curr.fi!=-1 and i<n){
    tr(prev,curr);
    prev = curr;
    curr = get(curr,arr[i]);
    i++;
  }
  // tr(prev,i,curr);
  if(curr.fi==-1){
    i--;
  }
  if(i==n){
    cout<<0<<endl;
    return 0;
  }
  if(prev.se<arr[i].fi){
    ans.pb(prev.se);
  }
  else{
    ans.pb(prev.fi);
  }
  ll cur = 0;
  for(ll j=i;j<n;j++){
    if(in(ans[cur],arr[j])){
      ans.pb(ans[cur]);
      cur++;
      continue;
    }
    if(ans[cur]<arr[j].fi){
      ans.pb(arr[j].fi);
      cur++;
    }
    else{
      ans.pb(arr[j].se);
      cur++;
    }
  }
  ll tot_ans = 0;
  cout<<ans<<endl;
  for(ll j=1;j<ans.size();j++){
    tot_ans += (abs(ans[j] - ans[j-1]));
  }
  cout<<tot_ans<<endl;
}
