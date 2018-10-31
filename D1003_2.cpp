// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%lld",&x)
#define sd2(x,y) scanf("%lld%lld",&x,&y)
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

ll n,q;
ll arr[300000];
unordered_map<ll,ll> mp,tt,mp_ans;
set<ll> s;
vector<ll> v;
ll temp;
ll ans = 0;
int n1;

void solve(ll no){
  ll k,i;
  for(int i1 = 0;i1<n1;i1++){
    i = v[i1];
    if(i<=no){
      k = mp[i];
      ans += min(k,no/i);
      mp[i] =k -  min(k,no/i);
      no -= min(k,no/i)*i;
    }
  }
  if(no>0){
    ans = -1;
  }
}

int main(){
  sd2(n,q);
  mp.reserve(40);
  mp.max_load_factor(1);
  tt.reserve(40);
  mp.max_load_factor(1);
  for(ll i=0;i<n;i++){
    cin>>arr[i];
    mp[arr[i]]++;
    s.insert(arr[i]);
  }
  for(auto i:s){
    v.pb(i);
    tt[i] = mp[i];
  }
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  n1 = v.size();
  while(q--){
    sd(temp);
    ans = 0;
    for(int i=29;i>=0;i--){
      if(temp&(1<<i)){
        solve(1<<i);
        if(ans==-1){
          break;
        }
      }
    }
    printf("%lld\n",ans);
    for(int i=0;i<n1;i++){
      mp[v[i]] = tt[v[i]];
    }
  }
}
