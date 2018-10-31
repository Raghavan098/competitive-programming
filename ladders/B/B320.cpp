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

int n,visited[200];
map<int,vector<int> > grp;
map<int,pair<int,int> > inp;
void add(int curp){
  for(int i=1;i<curp;i++){
    if((inp[curp].fi>inp[i].fi and inp[curp].fi<inp[i].se) or (inp[curp].se>inp[i].fi and inp[curp].se<inp[i].se)){
      grp[curp].pb(i);
      // grp[i].pb(curp);
    }
    if((inp[i].fi>inp[curp].fi and inp[i].fi<inp[curp].se) or (inp[i].se>inp[curp].fi and inp[i].se<inp[curp].se)){
      // grp[curp].pb(i);
      grp[i].pb(curp);
    }
  }
}
int x,y,a;
bool ans;
void dfs(int np){
  // tr(np);
  visited[np] = 1;
  if(np==y){
    ans = true;
  }
  for(int i=0;i<grp[np].size();i++){
    if(visited[grp[np][i]]==0){
      dfs(grp[np][i]);
    }
  }
}
int main(){
  cin>>n;
  int curp = 1;
  for(int i=0;i<n;i++){
    cin>>a;
    if(a==1){
      cin>>x>>y;
      inp[curp] = mp(x,y);
      add(curp);
      curp++;
    }
    else{
      ans = false;
      cin>>x>>y;
      for(int i=1;i<curp;i++){
        visited[i] = 0;
      }
      dfs(x);
      if(ans==true){
        cout<<"YES"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }
    }
  }
  return 0;
}
