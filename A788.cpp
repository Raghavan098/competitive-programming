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

ll n,arr[100010],b[100010],c[100010];

ll get_max_b(){
  ll maxs = -1;
  ll curr = 0;
  for(ll i=0;i<n;i++){
    if(curr+b[i]>0){
      curr+=b[i];
    }
    else{
      curr=0;
    }
    if(curr>maxs){
      maxs = curr;
    }
  }
  return maxs;
}

ll get_max_c(){
  ll maxs = -1;
  ll curr = 0;
  for(ll i=0;i<n;i++){
    if(curr+c[i]>0){
      curr+=c[i];
    }
    else{
      curr=0;
    }
    if(curr>maxs){
      maxs = curr;
    }
  }
  return maxs;
}

int main(){
  cin>>n;
  for(ll i=0;i<n;i++){
    cin>>arr[i];
  }
  for(ll i=0;i<n-1;i++){
    b[i] = abs(arr[i]-arr[i+1]);
    c[i] = abs(arr[i]- arr[i+1]);
    if(i%2==0){
      c[i]*=-1;
    }
    else{
      b[i]*=-1;
    }
  }
  if((n-1)%2==1){
    b[n-1]*=-1;
  }
  else{
    c[n-1]*=-1;
  }
  cout<<max(get_max_b(),get_max_c())<<endl;
}
