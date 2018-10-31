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

int n,l;
int ans1[200][200];
int dp[101];

int main(){
  cin>>n;
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 0;
  dp[3] = 1;
  for(int i=4;i<=100;i++){
    dp[i] = dp[i-1]+((i-1)*(i-2))/2;
    if(dp[i]>100000){
      l = i;
      break;
    }
  }
  // for(int i=0;i<=l;i++){
  //   cout<<dp[i]<<" "<<i<<endl;
  // }cout<<endl;
  int i=l-1;
  vector<int> ans;
  int s = 1;
  while(n){
    // tr(n);
    while(dp[i]<=n){
      for(int j=s;j<=s+i-1;j++){
        for(int k=s;k<=s+i-1;k++){
          if(j!=k){
            ans1[j][k] = 1;
          }
        }
      }
      n-=dp[i];
      s = s+i;
      // tr(s,n);
      for(int j=i-1;j>=2;j--){
        if((n-(j*(j-1))/2)>=0){
          for(int k=1;k<=j;k++){
            ans1[s][k] = 1;
            ans1[k][s] = 1;
          }
          n-=((j*(j-1))/2);
          s++;
        }
      }
    }
    i--;
  }
  // tr(n);
  // while(n>0){
  //   n-=1;
  //   ans.pb(3);
  // }
  // cout<<ans<<endl;
  // int s = 1;
  // for(int j=0;j<ans.size();j++){
  //   for(int k = s;k<=s+ans[j]-1;k++){
  //     for(int q = s;q<=s+ans[j]-1;q++){
  //       if(k!=q){
  //         ans1[k][q] = 1;
  //       }
  //     }
  //   }
  //   s+=ans[j];
  // }
  cout<<100<<endl;
  for(int i=1;i<=100;i++){
    for(int j=1;j<=100;j++){
      cout<<ans1[i][j];
    }cout<<endl;
  }
  return 0;
}
