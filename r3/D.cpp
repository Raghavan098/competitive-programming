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

ll get(ll n,ll m){
  if(m%2==1){
    // cout<<ll(n*(ceil(m/2.0)))<<endl;
    return ll(n*(ceil(m/2.0)));
  }
  else{
    if(n%2==0){
      // tr(ceil(m/2.0));
      ll tot = (n/2)*(m/2.0 + 1) + (n/2)*(m/2);
      // cout<<tot<<endl;
      return tot;
    }
    else{
      ll tot = (n/2)*(ceil(m/2.0) + 1) + (n/2)*(m/2) + m/2;
      // cout<<tot<<endl;
      return tot;
    }
  }
}

ll solve(){
  ll n,m;
  cin>>n>>m;
  cout<<min(get(n,m),get(m,n))<<endl;
  return 0;
}

int main(){ _
  ll t;
  cin>>t;
  while(t--){
    solve();
  }
}
