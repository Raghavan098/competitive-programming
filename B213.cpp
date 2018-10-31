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

ll combi[1000006];
int n,n1;
ll a[11];
ll dp[20][200];
const ll mod = 1e9 + 7;

long long binpow(long long val, long long deg, long long mod) {
        if (!deg) return 1 % mod;
        if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
        long long res = binpow(val ,deg >> 1, mod);
        return (res*res) % mod;
}
ll ncr(ll n,ll r){
  ll ans1 = combi[n];
  ll ans2 = (combi[n-r]*combi[r])%1000000007;
  ans2 = binpow(ans2,1000000007-2,1000000007);
  ll ans = (ans1*ans2)%1000000007;
  return ans;
}
int main(){
  n = 100;
  ll curr = 1;
  combi[0] =1;
  for(int i=1;i<=n;i++){
    combi[i] = curr;
    curr = (curr*(i+1))%1000000007;
  }
  cin>>n1;
  int s = 0;
  for(int i=0;i<10;i++){
    cin>>a[i];
    s+=a[i];
  }
  if(s>n){
    cout<<0<<endl;
    return 0;
  }
  for(int len=0;len<=n1;len++){
    for(int dig = 9;dig>=0;dig--){
      if(dig==0){
        for(int i=a[dig];i<=len;i++){
          if(len-1>=0 and i<=len-1)
            dp[dig][len] = (dp[dig][len] + (dp[dig+1][len-i]*(ncr(len-1,i)))%mod)%mod;
        }
      }
      else if(dig==9){
        if(len>=a[9]){
          dp[9][len] = 1;
        }
        else{
          dp[9][len] = 0;
        }
      }
      else{
        for(int i=a[dig];i<=len;i++){
          dp[dig][len] = (dp[dig][len] + (dp[dig+1][len-i]*(ncr(len,i)))%mod)%mod;
        }
      }
    }
  }
  ll final_ans = 0;
  for(int i=0;i<=n;i++){
    final_ans=(final_ans+dp[0][i])%mod;
  }
  cout<<final_ans<<endl;
  return 0;
}
