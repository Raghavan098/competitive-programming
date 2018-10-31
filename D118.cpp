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

ll dp[110][110][20];
const ll MOD = 100000000;
ll n1,n2,k1,k2;

ll get(ll n1,ll n2,ll state){
  // tr(n1,n2,state);
  if(n1==0 and n2==0){
    return 1;
  }
  if(n1==0 and n2>k2){
    return 0;
  }
  if(n2==0 and n1>k1){
    return 0;
  }
  if(dp[n1][n2][state]!=-1){
    return dp[n1][n2][state];
  }
  ll res = 0;
  if(state==0){
    for(int i=1;i<=min(k1,n1);i++){
      res+=get(n1-i,n2,1);
      res%=MOD;
    }
  }
  else{
    for(int i=1;i<=min(k2,n2);i++){
      res+=get(n1,n2-i,0);
      res%=MOD;
    }
  }
  dp[n1][n2][state] = res%MOD;
  return res%MOD;
}

int main(){
  cin>>n1>>n2>>k1>>k2;
  MEMS(dp,-1);
  ll res1 = get(n1,n2,0);
  MEMS(dp,-1);
  ll res2 = get(n1,n2,1);
  cout<<(res1+res2)%MOD<<endl;
  return 0;
}
