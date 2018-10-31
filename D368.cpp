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

int n,m,p;
multiset<int> e,w,found;
int a[300000],b[300000];

void print(multiset<int> s){
  for(auto i:s){
    cout<<i<<" ";
  }cout<<endl;
}

int main(){
  cin>>n>>m>>p;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<m;i++){
    cin>>b[i];
    w.insert(b[i]);
  }
  vector<int> ans;
  for(int x = 0;x<p;x++){
    int hel = m;
    int j = 0;
    int i;
    for(i=x,j = 0;i<n,j<m;i+=p,j++){
      if(w.find(a[i])!=w.end()){
        hel--;
        w.erase(w.find(a[i]));
      }
      else{
        e.insert(a[i]);
      }
    }
    if(hel==0){
      ans.pb(x);
    }
    int curr = x;
    for(;i<n;i+=p){
      if(curr>=n){
        break;
      }
      if(e.find(a[curr])==e.end()){
        w.insert(a[curr]);
        hel++;
      }
      else{
        e.erase(e.find(a[curr]));
      }
      if(w.find(a[i])!=w.end()){
        hel--;
        w.erase(w.find(a[i]));
      }
      else{
        e.insert(a[i]);
      }
      curr+=p;
      if(hel==0){
        ans.pb(curr);
      }
    }
    w.clear();
    e.clear();
    for(int tmp=0;tmp<m;tmp++){
      w.insert(b[tmp]);
    }
  }
  sort(ans.begin(),ans.end());
  cout<<ans.size()<<endl;
  for(auto i:ans){
    cout<<i+1<<" ";
  }cout<<endl;
  return 0;
}
