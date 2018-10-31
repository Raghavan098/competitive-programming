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

int r,g;
int dp[200005];
int mod = (int) 1e9 + 7;
int main(){
  cin>>r>>g;
  int mx_h;
  for(int i=0;i<1000;i++){
    if ((i*(i+1))/2>r+g) {
      mx_h = i-1;
      break;
    }
  }
  // tr(mx_h);
  dp[0] = 1;
  for(int h = 1;h<=mx_h;h++){
    int cur = (h*(h+1))/2;
    for(int r1 = r;r1>=0;r1--){
      int ans = 0;
      if(r1-h>=0){
        ans=(ans+dp[r1-h])%mod;
      }
      if(cur - r1 - h>=0){
        ans=(ans+dp[r1])%mod;
      }
      // tr(r1,ans,h);
      dp[r1] = ans;
    }
  }
  int tot_ans = 0;
  int cur = (mx_h*(mx_h+1))/2;
  for(int r1 = r;r1>=0 and (cur - r1)<=g;r1--){
    tot_ans = (tot_ans + dp[r1])%mod;
  }
  cout<<tot_ans<<endl;
}
