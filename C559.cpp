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

ll h,w,n;
vector<pair<ll,ll> > v;
const ll mod = 1000000007;

ll combi[200200];
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

ll ways[200200];

ll get(ll c,ll r){
  return ncr(c+r,c);
}

ll get2(ll c1,ll r1,ll c2,ll r2){
  ll x = c2 - c1;
  ll y = r2 - r1;
  return ncr((x+y),x);
}

int main(){

  cin>>h>>w>>n;
  combi[0] =1;
  ll curr = 1;
  for(int i=1;i<=200199;i++){
    combi[i] = curr;
    curr = (curr*(i+1))%1000000007;
  }
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    v.pb(mp(a,b));
  }
  v.pb(mp(h-1,w-1));
  sort(v.begin(),v.end());
  for(int i=0;i<=n;i++){
    ways[i] = get(v[i].fi,v[i].se);
  }
  for(int i=0;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      if(v[i].fi>v[j].fi or v[i].se>v[j].se)continue;
      ways[j] = (ways[j] - ways[i]*get2(v[i].fi,v[i].se,v[j].fi,v[j].se))%mod;
      while(ways[j]<0){
        ways[j] += mod;
      }
    }
  }
  // for(int i=0;i<=n;i++){
  //   cout<<ways[i]<<" ";
  // }cout<<endl;
  cout<<ways[n]<<endl;
  return 0;
}
