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


int solve(){
  int n;
  cin>>n;
  vector<string> v1,v2;
  string temp;
  map<string,int> ind;
  for(int i=0;i<n;i++){
    cin>>temp;
    ind[temp] = i;
    v1.pb(temp);
  }
  for(int i=0;i<n;i++){
    cin>>temp;
    v2.pb(temp);
  }
  int last = 0;
  int first = 0;
  int y;
  string x;
  for(int i=0;i<n;i++){
    x = v2[i];
    y = ind[x];
    if(y>last){
      last = y;
    }
    // tr(last,first,i);
    if(i==last){
      cout<<last - first + 1<<" ";
      first = i+1;
      last = first;
    }
  }
  cout<<endl;
  return 0;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
