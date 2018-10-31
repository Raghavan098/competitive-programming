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

string s1,s2;

#define MAXN 200000
const ll mod  = 1e9 + 7;

string s;
ll z[MAXN];
ll n;
void z_function(){
  ll L = 0;
  ll R = 0;
  for(ll i=1;i<n;i++){
    if(i>R){
      L = R = i;
      while(R<n and s[R-L]==s[R]){
        R++;
      }
      z[i] = R - L;
      R--;
    }
    else{
      ll k = i-L;
      if(z[k]<R-i+1){
        z[i] = z[k];
      }
      else{
        L = i;
        while(R<n and s[R-L]==s[R]){
          R++;
        }
        z[i] = R - L;
        R--;
      }
    }
  }
}
ll n1,n2;

ll good[200000];
ll ans[200000];
ll h1[200000];
ll h2[200000];

int main(){
  cin>>s1;
  cin>>s2;
  n1 = s1.size();
  n2 = s2.size();
  s = s2+s1;
  n = s.size();
  z_function();
  for(ll i=n2;i<n1+n2;i++){
    if(min(n2,z[i])==n2){
      good[i - n2] = 1;
    }
  }
  // for(ll i=0;i<n1;i++){
  //   cout<<good[i]<<" ";
  // }cout<<endl;
  for(ll i = n1-1;i>=0;i--){
    if(good[i]==0){
      ans[i] = ans[i+1];
    }
    else{
      ans[i] = (h2[i+n2] + n1 - i - n2 +1)%mod;
    }
    h1[i] = (h1[i+1]+ans[i])%mod;
    h2[i] = (h2[i+1]+h1[i])%mod;
  }
  // for(ll i=0;i<n1;i++){
  //   cout<<h1[i]<<" "<<h2[i]<<endl;
  // }
  ll tot_sum = 0;
  for(ll i=0;i<n1;i++){
    // cout<<ans[i]<<" ";
    tot_sum= (tot_sum + ans[i])%mod;
  }
  cout<<tot_sum<<endl;
  // tr(tot_sum);
  return 0;
}
