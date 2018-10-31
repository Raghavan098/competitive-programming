// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%lld%lld",&x,&y)
#define sd3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
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
#define inf 1000000000001

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

ll n,x;
unordered_map<ll,vector<pair<ll,ll> > > st_mp,ed_mp;
unordered_map<ll,vector<ll> > st_mp_min,ed_mp_min;
vector<pair<pair<ll,ll> , ll> > inp;

void preprocess(){
  for(auto it:st_mp){
    ll ind = it.fi;
    ll siz = (it.se).size();
    sort(st_mp[ind].begin(),st_mp[ind].end());
    sort(ed_mp[ind].begin(),ed_mp[ind].end());
    st_mp_min[ind].resize(siz);
    ed_mp_min[ind].resize(siz);
  }
  for(auto it:st_mp){
    ll ind = it.fi;
    ll siz = (it.se).size();
    ll curr = inf;
    for(ll i=siz-1;i>=0;i--){
      st_mp_min[ind][i] = min(curr,st_mp[ind][i].se);
      curr = min(curr,st_mp[ind][i].se);
    }
    curr = inf;
    for(ll i=0;i<siz;i++){
      ed_mp_min[ind][i] = min(curr,ed_mp[ind][i].se);
      curr = min(curr,ed_mp[ind][i].se);
    }
  }
}
ll get(ll ind,ll lft){
  if(st_mp.find(ind)==st_mp.end()){
    return -1;
  }
  ll ans = -1;
  ll l = 0;
  auto &v = st_mp[ind];
  ll r = v.size()-1;
  ll mid;
  while(l<=r){
    mid = (l+r)/2;
    if(v[mid].fi>=lft){
      ans = mid;
      r = mid-1;
    }
    else{
      l = mid+1;
    }
  }
  // tr(ans);
  if(ans==-1){
    return -1;
  }
  return st_mp_min[ind][ans];
}

ll get2(ll ind,ll rgt){
  if(st_mp.find(ind)==st_mp.end()){
    return -1;
  }
  ll ans = -1;
  ll l = 0;
  auto &v = ed_mp[ind];
  ll r = v.size()-1;
  ll mid;
  while(l<=r){
    mid = (l+r)/2;
    if(v[mid].fi<=rgt){
      ans = mid;
      l = mid+1;
    }
    else{
      r = mid-1;
    }
  }
  // tr(ans);
  if(ans==-1){
    return -1;
  }
  return ed_mp_min[ind][ans];
}
int main(){
  sd2(n,x);
  for(ll i=0;i<n;i++){
    ll l,r,c;
    sd3(l,r,c);
    inp.pb(mp(mp(l,r),c));
    st_mp[r - l +1].pb(mp(l,c));
    ed_mp[r - l +1].pb(mp(r,c));
  }
  preprocess();
  ll ans = inf;
  for(ll i=0;i<n;i++){
    ll l,r,c;
    l = inp[i].fi.fi;
    r = inp[i].fi.se;
    c = inp[i].se;
    ll m1 = get(x -(r - l +1),r+1);
    if(m1!=-1){
      ans = min(ans,c+m1);
    }
    ll m2 = get2(x - (r-l+1),l-1);
    if(m2!=-1){
      ans = min(ans,c+m2);
    }
  }
  if(ans!=inf)
    printf("%lld\n",ans);
  else{
    puts("-1");
  }
  return 0;
}
