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
ll arr[1000100];
const ll mod = 998244353;
ll dp[1000100];
ll cumu[1000100];

int main(){ _
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    if(i==0){
      cumu[i] = arr[i];
    }
    else{
      cumu[i] = (arr[i] + cumu[i-1])%mod;
    }
  }
  ll curr = arr[0];
  ll temp = arr[0];
  dp[0] = arr[0];
  for(int i=1;i<n;i++){
    // tr(i,temp,curr,cumu[i]);
    dp[i] = curr;
    dp[i] = (dp[i] + cumu[i])%mod;
    dp[i] = (dp[i] + temp)%mod;
    curr = (curr + dp[i])%mod;
    temp = (temp*2)%mod;
    temp = (temp + cumu[i])%mod;
  }
  cout<<dp[n-1]<<endl;
  return 0;
}
