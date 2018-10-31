// g++ -std=c++14

#include<bits/stdc++.h>

typedef unsigned long long ll;
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

ll n;

int main(){
  cin>>n;
  ll l = 1;
  ll r = n-1;
  ll mid,a,b;
  if(n==2){
    cout<<1<<endl;
    return 0;
  }
  ll req = (n*(n-1))/4;
  ll sum;
  ll temp = (n*(n-1))/2;
  ll sum2;
  ll ans;
  if(temp%2==1){
    req = req+1;
  }
  // tr(req,temp);
  while(l<=r){
    mid = (l+r)/2;
    a = n-1;
    b = n-mid;
    sum = (mid)*(a+b)/2;
    sum2 = (mid-1)*(a+b+1)/2;
    // tr(sum,l,r,a,b,mid,sum2);
    if(sum>=req and req>sum2){
      ans = mid;
    }
    if(sum>req){
      r = mid-1;
    }
    else{
      l = mid+1;
    }
  }
  printf("%lld\n",ans);
}
