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

ll n,k;
ll arr[100];

bool check(ll m){
  bool dp[100][100];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=k;j++){
      dp[i][j] = false;
    }
  }
  dp[0][0] = true;
  ll sum;
  for(int pos=1;pos<=n;pos++){
    for(int part=1;part<=k;part++){
      if(dp[pos-1][part-1]==false){
        continue;
      }
      sum = 0;
      for(int newpos = pos;newpos<=n;newpos++){
        sum+=arr[newpos];
        if((sum&m)==m){
          dp[newpos][part] = true;
        }
      }

    }
  }
  return dp[n][k];
}

int main(){
  cin>>n>>k;
  for(ll i=1;i<=n;i++){
    cin>>arr[i];
  }
  ll ans = 0;
  ll temp;
  for(ll i = 60;i>=0;i--){
    temp = ans + (1LL<<i);
    // tr(temp,i,check(temp));
    if(check(temp)){
      ans = temp;
    }
  }
  cout<<ans<<endl;
}
