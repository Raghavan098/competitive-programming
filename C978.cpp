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

ll n,m,x,l,r,mid,ans;
ll arr[200000],cum[200000];

int main(){
  cin>>n>>m;
  for(ll i=1;i<=n;i++){
    cin>>arr[i];
  }
  for(ll i=1;i<=n;i++){
    cum[i] = cum[i-1]+arr[i];
  }
  cum[n+1] = 10000000002;
  // for(ll i=1;i<=n;i++){
  //   cout<<cum[i]<<" ";
  // }cout<<endl;
  for(ll i=0;i<m;i++){
    cin>>x;
    l = 1;
    r = n;
    while(l<=r){
      mid = (l+r)/2;
      if(cum[mid]>=x){
        ans = mid;
        r = mid-1;
      }
      else{
        l = mid+1;
      }
    }
    // tr(ans,cum[ans]);
    if(cum[ans]!=x){
      ans--;
    }
    if(x - cum[ans]==0){
      cout<<ans<<" "<<x - cum[ans-1]<<endl;
    }
    else
      cout<<ans+1<<" "<<x - cum[ans]<<endl;
  }
  return 0;
}
