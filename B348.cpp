// g++ -std=c++14

#include<bits/stdc++.h>

typedef unsigned long long ll;
typedef long double lld;
using namespace std;

#define sd1(x) scanf("%lld",&x)
#define sd2(x,y) scanf("%lld%lld",&x,&y)
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
#define inf 20000000000000



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

bool overflow = false;

ll mul(ll x, ll y){

    if(x == 0 || y == 0)    return 0;
    return x*y;
}


struct node{
  ll sum;
  ll branc;
  ll ans;
};

ll gcd(ll a,ll b){
	if(a<b)
		swap(a,b);
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b){
	ll val=__gcd(a,b);
	if(val==0)
		return 0;
	return a*b/val;
}


ll n;
ll tot_sum = 0;
vector<ll> grp[100100];
ll app[100100];
node all[100100];
ll visited[100100];

void dfs(ll no){
  // tr(no);
  visited[no] = 1;
  if(grp[no].size()==1){
    all[no].sum = app[no];
    all[no].branc = 1;
    all[no].ans = 0;
  }
  else{
    ll lc = 1;
    ll min_sum = inf;
    ll aa = 0;
    ll bb = 1;
    vector<ll> child;
    ll cc = 0;
    for(auto temp:grp[no]){
      if(visited[temp]==0){
        dfs(temp);
        min_sum = min(min_sum,all[temp].sum);
        // lc = lcm(lc,all[temp].branc);
        ll gcd1 = __gcd(lc, all[temp].branc);
        if(gcd1 != 0)
          lc = ((lc )/ gcd1)* all[temp].branc;
        else{
          cout<<tot_sum<<endl;
          exit(0);
        }
        aa += all[temp].ans;
        child.pb(temp);
        cc++;
      }
    }
    if(lc==0){
      cout<<tot_sum<<endl;
      exit(0);
    }
    ll pre = mul((min_sum/lc),lc);
    ll tot = 0;
    for(auto temp:child){
      aa += (all[temp].sum - pre);
      tot+=pre;
    }
    all[no].sum = tot;
    all[no].branc = mul(lc,cc);
    all[no].ans = aa;
  }
  // tr(no,all[no].sum,all[no].branc,all[no].ans);
}

int main(){
  sd1(n);
  for(ll i=1;i<=n;i++){
    sd1(app[i]);
    all[i].branc = 1;
    all[i].sum = app[i];
    all[i].ans = 0;
    tot_sum += app[i];
  }

  for(ll i=0;i<n-1;i++){
    ll a,b;
    sd2(a,b);
    grp[a].pb(b);
    grp[b].pb(a);
  }
  all[1].ans = tot_sum;
  dfs(1);
  cout<<all[1].ans<<endl;
  return 0;
}
