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

ll n,m,k,p;
ll arr[2000][2000];
multiset<ll> r,c;
ll s;
ll off_r,off_c;

int main(){
  cin>>n>>m>>k>>p;
  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
      cin>>arr[i][j];
    }
  }
  for(ll i=0;i<n;i++){
    s = 0;
    for(ll j=0;j<m;j++){
      s+=arr[i][j];
    }
    r.insert(s);
  }
  for(ll j=0;j<m;j++){
    s = 0;
    for(ll i=0;i<n;i++){
      s+=arr[i][j];
    }
    c.insert(s);
  }
  ll tr,tc;
  ll tot_ans = -100000000;
  tot_ans*= -tot_ans;
  vector<ll> vc,vr;
  vc.pb(0LL);
  vr.pb(0LL);
  for(ll i=0;i<=k;i++){
    tr = *r.rbegin();
    tc = *c.rbegin();
    r.erase(r.find(tr));
    vr.pb(tr);
    r.insert(tr - p*m);
    c.erase(c.find(tc));
    vc.pb(tc);
    c.insert(tc - p*n);
  }
  for(int i=1;i<=k;i++){
    vr[i] +=vr[i-1];
    vc[i] +=vc[i-1];
  }
  // cout<<vr<<endl;
  // cout<<vc<<endl;
  for(int i=0;i<=k;i++){
    // tr(vr[i] + vc[k-i] - ((i)*(k-i)*p));
    tot_ans = max(tot_ans,vr[i] + vc[k-i] - ((i)*(k-i)*p));
  }
  cout<<tot_ans<<endl;
  return 0;
}
