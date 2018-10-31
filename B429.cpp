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

ll n,m;
ll arr[2000][2000];
ll dp1[2000][2000];
ll dp2[2000][2000];
ll dp3[2000][2000];
ll dp4[2000][2000];

int main(){
  cin>>n>>m;
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=m;j++){
      cin>>arr[i][j];
    }
  }
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=m;j++){
      dp1[i][j] = arr[i][j] + max(dp1[i-1][j],dp1[i][j-1]);
    }
  }
  for(ll i=n;i>=1;i--){
    for(ll j=m;j>=1;j--){
      dp2[i][j] = arr[i][j] + max(dp2[i+1][j],dp2[i][j+1]);
    }
  }
  for(ll i=n;i>=1;i--){
    for(ll j=1;j<=m;j++){
      dp3[i][j] = arr[i][j] + max(dp3[i+1][j],dp3[i][j-1]);
    }
  }
  for(ll i=1;i<=n;i++){
    for(ll j=m;j>=1;j--){
      dp4[i][j] = arr[i][j] + max(dp4[i-1][j],dp4[i][j+1]);
    }
  }
  ll final_ans = -1;
  // for(int i=1;i<=n;i++){
  //   for(int j=1;j<=m;j++){
  //     cout<<dp4[i][j]<<" ";
  //   }cout<<endl;
  // }
  for(ll i=2;i<=n-1;i++){
    for(ll j=2;j<=m-1;j++){
      final_ans = max(final_ans,(dp1[i-1][j] + dp2[i+1][j] + dp3[i][j-1] + dp4[i][j+1]));
      final_ans = max(final_ans,(dp1[i][j-1] + dp2[i][j+1] + dp3[i+1][j] + dp4[i-1][j]));
    }
  }
  cout<<final_ans<<endl;
  return 0;
}
