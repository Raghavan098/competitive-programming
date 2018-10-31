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

ll n,h;
vector<pair<ll,ll> >arr;
ll ans[200000];

int main(){
  cin>>n>>h;
  for(int i=0;i<n;i++){
    ll temp;
    cin>>temp;
    arr.pb(mp(temp,i));
  }
  sort(arr.begin(),arr.end());
  ll m1 =(arr[n-1].fi + arr[n-2].fi) -  (arr[0].fi + arr[1].fi);
  if(n==2){
    cout<<0<<endl;
    cout<<1<<" "<<1<<endl;
    return 0;
  }
  ll fmi = min((arr[1].fi + arr[0].fi + h),(arr[1].fi + arr[2].fi));
  ll fmx = max((arr[0].fi + arr[n-1].fi +h),(arr[n-1].fi + arr[n-2].fi));
  ll m2 = fmx - fmi;
  if(m2<m1){
    cout<<m2<<endl;
    ans[arr[0].se] = 1;
    for(int i=0;i<n;i++){
      if(ans[i]==0)
        cout<<2<<" ";
      else
        cout<<1<<" ";
    }cout<<endl;
  }
  else{
    cout<<m1<<endl;
    for(int i=0;i<n;i++){
      cout<<1<<" ";
    }cout<<endl;
  }
  return 0;
}
