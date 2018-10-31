// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

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

ll n,k,arr[100010],prex[100010],sux[100010],tot[100010],t_arr[100010],tot1;

int main(){
  cin>>n>>k;
  for(ll i=1;i<=n;i++){
    cin>>arr[i];
  }
  for(ll i=1;i<=n;i++){
    cin>>t_arr[i];
    if(t_arr[i]==0){
      prex[i] = prex[i-1];
    }
    else{
      prex[i] = prex[i-1]+arr[i];
    }
    tot[i] = tot[i-1]+arr[i];
  }
  if(t_arr[n-1])
    sux[n-1] = arr[n-1];
  else{
    sux[n-1] = 0;
  }
  for(ll i=n-2;i>=0;i--){
    if(t_arr[i])
      sux[i] = sux[i+1]+arr[i];
    else{
      sux[i] = sux[i+1];
    }
  }
  // for(ll i=1;i<=n;i++){
  //   tr(i,prex[i],sux[i],tot[i]);
  // }
  ll ans = -1;
  for(ll i=1;i<=n-k+1;i++){
    tot1 = prex[i-1]+tot[i+k-1] - tot[i-1]+prex[n] - prex[i+k-1];
    // tr(tot1,i);
    ans = max(ans,tot1);
  }
  cout<<ans<<endl;
}
