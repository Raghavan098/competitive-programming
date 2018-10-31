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

lld n,l,v1,v2,k;

bool check(lld T){
  lld temp_time;
  lld time_esp = 0.0;
  lld st = 0.0;
  lld x,t;
  for(int i=0;i<ceil(n/k);i++){
    x = ((T-time_esp)*v1*v2 + v1*st - l*v2)/(v1-v2);
    t = (x - st)/(v2);
    if ((l-st)/v2 + time_esp > T) return false;
    time_esp+=t;
    st+=t*v1;
    if(!(i+1>=ceil(n/k))){
      t = (x - st)/(v1+v2);
      st += v1*t;
      time_esp += t;
    }
  }
  return true;
}

int main(){
  cin>>n>>l>>v1>>v2>>k;

  lld l1 = 0;
  lld r1 = (l*1.0)/v1;
  lld mid;
  lld ans;
  // tr(l1,r1);
  for(int i=0;i<=100;i++){
    mid = (l1+r1)/2;
    // tr(mid,check(mid));
    if(check(mid)){
      ans = mid;
      r1 = mid;
    }
    else{
      l1 = mid;
    }
  }
  printf("%0.8Lf\n",ans);
  return 0;
}
