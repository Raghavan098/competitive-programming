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

ll n,x,y,c,l,r,up,down;

ll sum(ll x){
  return (x*(x+1))/2LL;
}

bool f(ll t){
  ll ans = t*t + (t+1)*(t+1);
  if(t>l){
    ans -= ((t - l)*(t - l));
  }
  if(t>r){
    ans -= ((t - r)*(t - r));
  }
  if(t>up){
    ans -= ((t - up)*(t - up));
  }
  if(t>down){
    ans -= ((t - down)*(t - down));
  }
  if(t>(l+up)){
    ans += sum(t - l - up - 1);
  }
  if(t>(l+down)){
    ans += sum(t - l - down - 1);
  }
  if(t>(r+up)){
    ans += sum(t - r - up - 1);
  }
  if(t>(r+down)){
    ans += sum(t - r - down - 1);
  }
  return (ans>=c);
}

int main(){
  cin>>n>>x>>y>>c;
  l = x - 1;
  r = n - x;
  up = y - 1;
  down = n - y;
  if(c<=1){
    cout<<0<<endl;
    return 0;
  }
  ll lft = 2;
  ll rgt = 2*n;
  ll ans;
  while(lft<=rgt){
    ll mid = (lft+rgt)/2;
    if(f(mid)){
      ans = mid;
      rgt = mid - 1;
    }
    else{
      lft = mid + 1;
    }
  }
  cout<<ans<<endl;
}
