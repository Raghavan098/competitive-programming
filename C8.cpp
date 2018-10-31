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

const int N = 30;
int a,b,n;
int x[N],y[N];
int dist[N][N];
int dp[1<<25],next1[1<<25],next2[1<<25];
int get_dist(int i,int j){
  return ((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
}

int f(int mask){
  // tr(mask);
  if(mask>=((1<<n) -1)){
    return 0;
  }
  int x = dp[mask];
  if(x!=-1){
    return x;
  }
  int ind;
  for(int i=0;i<n;i++){
    if((mask&(1<<i))==0){
      ind = i;
      break;
    }
  }
  int r = f(mask|(1<<ind)) + 2*dist[ind][n];
  next1[mask] = ind+1;
  next2[mask] = -1;
  int temp;
  for(int i=0;i<n;i++){
    if((mask&(1<<i))==0){
      temp = f(mask|(1<<i)|(1<<ind)) + dist[ind][i] + dist[i][n] + dist[ind][n];
      if(temp<r){
        r = temp;
        next1[mask] = ind+1;
        next2[mask] = i+1;
      }
    }
  }
  return dp[mask] = r;
}

void p(int mask){
  if(mask>=((1<<n)-1)){
    return ;
  }
  if(next2[mask]!=-1){
    cout<<0<<" "<<next1[mask]<<" "<<next2[mask]<<" ";
    p(mask|(1<<(next1[mask]-1))|(1<<(next2[mask]-1)));
  }
  else{
    cout<<0<<" "<<next1[mask]<<" ";
    p(mask|(1<<(next1[mask]-1)));
  }
  return;
}

int main(){ _
  cin>>a>>b>>n;
  x[n] = a;
  y[n] = b;
  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
  }
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      dist[i][j] = get_dist(i,j);
    }
  }
  MEMS(dp,-1);
  cout<<f(0)<<endl;
  p(0);
  cout<<0<<endl;
}
