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

ll n,k,arr[300000],ans[300000],x,y;
unordered_map<ll,vector<ll> > mp;
set<ll> s;
vector<ll> tt;
std::vector<ll> all;

int main(){ _
  scanf("%lld%lld",&n,&k);
  for(ll i=1;i<=n;i++){
    scanf("%lld",&arr[i]);
    mp[arr[i]].pb(i);
    tt.pb(arr[i]);
  }
  ll curr = 0;
  ll temp2;
  sort(tt.begin(),tt.end());
  ll prev = -1;
  for(int i=0;i<tt.size();i++){
    if(tt[i]!=prev){
      all.pb(tt[i]);
      prev = tt[i];
    }
  }
  vector<ll> temp;
  for(int it=0;it<all.size();it++){
    temp2 = all[it];
    temp = mp[temp2];
    for(ll i=0;i<temp.size();i++){
      ans[temp[i]] = curr;
    }
    curr+=temp.size();
  }
  for(ll i=0;i<k;i++){
    scanf("%lld%lld",&x,&y);
    if(arr[x]>arr[y]){
      ans[x]--;
    }
    else if(arr[y]>arr[x]){
      ans[y]--;
    }
  }
  for(ll i=1;i<=n;i++){
    printf("%lld ",ans[i]);
  }printf("\n");
  return 0;
}
