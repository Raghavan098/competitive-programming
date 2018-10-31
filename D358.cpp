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

const int N = 3003;
int n;
int a[N],b[N],c[N];
int dp[N][2];

int f(int curr,int prev){

  int x = dp[curr][prev];
  if(x!=-1){
    return x;
  }

  if(curr==n-1){
    if(prev==1){
      return dp[curr][prev] = b[curr];
    }
    else{
      return dp[curr][prev] = a[curr];
    }
  }

  if(prev==0){
    int r1 = f(curr+1,1) + a[curr];
    int r2 = f(curr+1,0) + b[curr];
    return dp[curr][prev] = max(r1,r2);
  }
  else if(prev==1){
    int r1 = f(curr+1,1) + b[curr];
    int r2 = f(curr+1,0) + c[curr];
    return dp[curr][prev] = max(r1,r2);
  }
}

int main(){ _
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>b[i];
  }
  for(int i=0;i<n;i++){
    cin>>c[i];
  }
  MEMS(dp,-1);
  cout<<f(0,0)<<endl;
  return 0;
}
