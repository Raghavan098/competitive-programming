// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

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

ll no;

bool cf(int i){
  int oc=0,zc=0;
  while(i>1){
    if(i%2==0){
      zc++;
    }
    else{
      oc++;
    }
    i/=2;
  }
  if(oc==zc){
    return true;
  }
  return false;
}

ll con(int k){
  ll ans = 0;
  ll cur = 0;
  while(k>1){
    if(k%2==0){
      ans+=4*pow(10,cur);
    }
    else{
      ans+=7*pow(10,cur);
    }
    cur++;
    k/=2;
  }
  return ans;
}
ll k;
vector<ll> v;
int main(){
  cin>>no;
  for(int i=2;i<=1600;i++){
    // tr(cf(i));
    if(cf(i)){
      k = con(i);
      // tr(k);
      v.pb(k);
    }
  }
  sort(v.begin(),v.end());
  // tr(v);
  for(int i=0;i<v.size();i++){
    if(v[i]>=no){
      cout<<v[i]<<endl;
      return 0;
    }
  }
  return 0;
}
