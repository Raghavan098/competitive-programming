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

const ll N = 1e6 + 5;
ll mobius[N];
ll h[N];
ll f[N];
ll sieve[N];
ll numFac[N];

// THE GREAT MOBIUS INVERSION :)


void calc_mobius(){
  memset(mobius,-1,sizeof(mobius));
  for(ll i=2;i<=N;i++){
    if(sieve[i] == 0){
      for(ll j=i;j<=N;j+=i){
        if(j != i)  sieve[j] = 1;
        numFac[j]++;
        if(j % (i*i) == 0)
            mobius[j] = 0;
      }
    }
  }

  mobius[1] = 1;
  for(ll i=2;i<=N;i++){
    if(mobius[i] == -1){
      if(numFac[i] % 2 == 0)  mobius[i] = 1;
      else    mobius[i] = -1;
    }
  }
}

void calc_h(){
  h[1] = 1;
  for(ll i=2;i<=N;i++){
    h[i] = 0;
  }
}
// calculation of inverse mobius function
void calc_f(){
  for(ll i=1;i<=N;i++){
    for(ll j=i;j<=N;j+=i){
      f[j] += h[i]*mobius[j/i];
    }
  }
}

const ll MAXN = 500500;

ll n,q;
ll arr[MAXN];
ll cnt[MAXN];
ll active[MAXN];
ll ans;

ll C(ll x) {
  if (x<=1)
    return 0;
  return (x*(x-1))/2;
}

void add(ll x){
  for(ll i=1;i*i<=x;i++){
    if(x%i!=0)continue;
    ans -= mobius[i]*C(cnt[i]);
    cnt[i]++;
    ans += mobius[i]*C(cnt[i]);
    if(x/i!=i){
      ans -= mobius[x/i]*C(cnt[x/i]);
      cnt[x/i]++;
      ans += mobius[x/i]*C(cnt[x/i]);
    }
  }
  cout<<ans<<endl;
}

void remove(ll x){
  for(ll i=1;i*i<=x;i++){
    if(x%i!=0)continue;
    ans -= mobius[i]*C(cnt[i]);
    cnt[i]--;
    ans += mobius[i]*C(cnt[i]);
    if(x/i!=i){
      ans -= mobius[x/i]*C(cnt[x/i]);
      cnt[x/i]--;
      ans += mobius[x/i]*C(cnt[x/i]);
    }
  }
  cout<<ans<<endl;
}

int main(){ _
  calc_mobius();
  calc_h();
  calc_f();
  // template ends now calculate cnt2 and proceed
  cin>>n>>q;
  for(ll i=1;i<=n;i++){
    cin>>arr[i];
  }
  while(q--){
    ll pos;
    cin>>pos;
    active[pos] ^= 1;
    if(active[pos]==1){
      add(arr[pos]);
    }
    else{
      remove(arr[pos]);
    }
  }
}
