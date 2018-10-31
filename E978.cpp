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


int main(){
  ll n,w,arr[2000],lb,up;
  cin>>n>>w;
  for(ll i=0;i<n;i++){
    cin>>arr[i];
  }
  if(arr[n-1]<0){
    ll a = w ;
    ll b = -arr[n-1];
    lb = min(a,b);
    up = max(a,b);
    // tr(a,b);
  }
  else{
    ll a = w-arr[n-1];
    ll b = 0;
    lb = min(a,b);
    up = max(a,b);
  }
  if(lb<0 or up>w){
    cout<<0<<endl;
    return 0;
  }
  // tr(lb,up);
  for(ll i=n-2;i>=0;i--){
    if(arr[i]<0){
      lb = (lb-arr[i]);
      up = min(up-arr[i],w);
      if(lb>w){
        cout<<0<<endl;
        return 0;
      }
    }
    else{
      lb = max((ll)0,lb - arr[i]);
      up = up - arr[i];
      if(up<0){
        cout<<0<<endl;
        return 0;
      }
      // tr(lb,up);
    }
    // tr(lb,up);
  }
  cout<<up-lb+1<<endl;
  return 0;
}
