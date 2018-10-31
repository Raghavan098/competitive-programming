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

const ll MAXN = 10000000;
const ll MOD = 1e9+7;

ll t,l,r;
ll n;
ll spf[MAXN];
ll dp[MAXN];
void sieve()
{
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)
        spf[i] = i;
    for (ll i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (ll i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (ll j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

vector<ll> getFactorization(ll x)
{
    vector<ll> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        return ret;
        x = x / spf[x];
    }
    return ret;
}

int main(){ _
  cin>>t>>l>>r;
  sieve();
  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 3;
  for(ll i=4;i<=r;i++){
    auto temp = getFactorization(i);
    if(temp[0]==i){
      dp[i] = ((i*(i-1))/2)%MOD;
    }
    else{
      ll x = temp[0];
      dp[i] = ((dp[x]*(i/x))%MOD + dp[i/x])%MOD;
      while(dp[i]<0){
        dp[i]+=MOD;
      }
    }
  }
  ll curr = 1;
  ll ans = 0;
  for(ll i=l;i<=r;i++){
    ans =(ans + curr*dp[i])%MOD;
    while(ans<0){
      ans+=MOD;
    }
    curr=(curr*t)%MOD;
    while(curr<0){
      curr+=MOD;
    }
  }
  cout<<ans<<endl;
  return 0;
}
