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

vector<ll> arr;
ll n;
vector<ll> v;
multiset<ll> s;
ll done[300300];

int main(){
  arr.resize(35);
  arr[0] = 1;
  for(ll i=1;i<=33;i++){
    arr[i] = arr[i-1]*2;
  }
  cin>>n;
  v.resize(n);
  for(ll i=0;i<n;i++){
    cin>>v[i];
    s.insert(v[i]);
  }
  for(ll i=0;i<n;i++){
    ll temp = v[i];
    ll here;
    s.erase(s.find(temp));
    for(ll j =0;j<=32;j++){
      if(arr[j]>temp){
        here = j;
        break;
      }
    }
    for(ll j = here;j<=32;j++){
      if(s.find(arr[j] - temp)!=s.end()){
        done[i] = 1;
        break;
      }
    }
    s.insert(temp);
  }
  ll ans = 0;
  for(ll i=0;i<n;i++){
    if(done[i]==0){
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
