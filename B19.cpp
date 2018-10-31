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

const ll N = 4004;
ll n;
ll t[N],c[N];
ll dp[N][N];
ll par = 2000;

ll f(ll pos,ll t_i){
  if(pos == n-1){
    if(t_i<0 and (t_i + t[pos])>=0){
      return c[pos];
    }
    else if(t_i<0){
      return inf;
    }
    else if(t_i>0){
      return 0;
    }
    else{
      return c[pos];
    }
  }
  ll x = dp[pos][t_i + par];
  if(x!=-1){
    return x;
  }
  x = f(pos+1, t_i - 1);
  ll y = f(pos + 1, min((t_i + t[pos]),n)) + c[pos];
  return dp[pos][t_i + par] = min(x,y);
}

int main(){ _
  cin>>n;
  for(ll i=0;i<n;i++){
    cin>>t[i]>>c[i];
  }
  MEMS(dp,-1);
  cout<<f(0,0)<<endl;
  return 0;
}
