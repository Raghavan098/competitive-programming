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

int n,f[200000],pre[200000],h[200000],g[200000];
map<int,int> mp;

int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>f[i];
    pre[f[i]] = 1;
  }
  int curr = 1;
  for(int i=1;i<=n;i++){
    if(pre[i]==1 and f[i]!=i){
      cout<<-1<<endl;
      return 0;
    }
    else if(pre[i]==1){
      h[curr] = i;
      mp[i] = curr;
      g[i] = curr;
      curr++;
    }
  }
  for(int i=1;i<=n;i++){
    if(g[i]==0){
      g[i] = mp[f[i]];
    }
  }
  cout<<curr-1<<endl;
  for(int i=1;i<=n;i++){
    cout<<g[i]<<" ";
  }cout<<endl;
  for(int i=1;i<curr;i++){
    cout<<h[i]<<" ";
  }cout<<endl;
  return 0;
}
