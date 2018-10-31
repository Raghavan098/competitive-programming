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


vector<ll> get(vector<ll>a,vector<ll> b,ll n){
  vector<ll> ans;
  ans.resize(n);
  for(ll i=0;i<n;i++){
    ans[i] = b[a[i]-1];
  }
  return ans;
}

ll solve(){
  ll n,m;
  cin>>m>>n;
  vector<vector<ll> > v;
  for(ll i=0;i<m;i++){
    vector<ll> temp;
    for(ll j=0;j<n;j++){
      ll a;
      cin>>a;
      temp.pb(a);
    }
    v.pb(temp);
  }
  ll q;
  cin>>q;
  while(q--){
    ll a,b;
    cin>>a>>b;
    a--;
    b--;
    if(a==b){
      ll ans = 0;
      for(ll i=0;i<n;i++){
        ans+=((i+1)*v[a][i]);
      }
      cout<<ans<<endl;
      continue;
    }
    vector<ll> temp = get(v[a],v[a+1],n);
    for(ll i=a+2;i<=b;i++){
      temp = get(temp,v[i],n);
      // tr(temp);
    }
    ll ans = 0;
    // tr(temp);
    for(ll i=0;i<n;i++){
      ans+=((i+1)*temp[i]);
    }
    cout<<ans<<endl;
  }
}

int main(){
  ll t;
  cin>>t;
  while(t--){
    solve();
  }
}
