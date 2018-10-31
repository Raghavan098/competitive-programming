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

set<ll> primes;
bool prime[300001];
ll n,m,arr[1000][1000],ans,n1,m1;

void SieveOfEratosthenes(ll n)
{
    for(ll i=0;i<200001;i++){
      prime[i] = true;
    }
    for (ll p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (ll p=2; p<=n; p++)
       if (prime[p])
          primes.insert(p);
}

int main (){
  cin>>n1>>m1;
  for(ll i=0;i<n1;i++){
    for(ll j =0;j<m1;j++){
      cin>>arr[i][j];
    }
  }
  ll count=0;
  SieveOfEratosthenes(200001);
  ans = INT_MAX;
  prime[1] = false;
  for(ll i=0;i<n1;i++){
    count =0;
    for(ll j=0;j<m1;j++){
      // tr(arr[i][j],prime[arr[i][j]]);
      if(!prime[arr[i][j]]){
        count+=(*primes.upper_bound(arr[i][j]))-arr[i][j];
      }
    }
    ans = min(ans,count);
  }
  for(ll i=0;i<m1;i++){
    count =0;
    for(ll j=0;j<n1;j++){
      if(!prime[arr[j][i]]){
        count+=(*primes.upper_bound(arr[j][i]))-arr[j][i];
      }
    }
    ans = min(ans,count);
  }
  cout<<ans<<endl;
  return 0;
}
