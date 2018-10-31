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

const ll N =  21;
ll n,m,k;
map<ll,ll> v[N][N];
ll arr[N][N];
ll half;
ll ans;
void calc_down(ll r,ll c,ll val,ll cnt){
  val ^= arr[r][c];
  if(cnt==half){
    ++v[r][c][val];
    return;
  }
  if(r + 1<n){
    calc_down(r+1,c,val,cnt+1);
  }
  if(c+1<m){
    calc_down(r,c+1,val,cnt+1);
  }
}

void calc_up(ll r,ll c,ll cnt,ll val){
  if(cnt == n+m-2-half){
    if((v[r][c].count(val^k))){
      ans += v[r][c][val^k];
    }
    return ;
  }
  if(r>0){
    calc_up(r-1,c,cnt+1,(val^arr[r][c]));
  }
  if(c>0){
    calc_up(r,c-1,cnt+1,(val^arr[r][c]));
  }
}

int main(){
  cin>>n>>m>>k;
  half = (n + m -2)/2;
  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
      cin>>arr[i][j];
    }
  }
  calc_down(0,0,0,0);
  calc_up(n-1,m-1,0,0);
  cout<<ans<<endl;
}
