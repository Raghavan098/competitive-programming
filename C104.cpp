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

int n,m,a,b;
map<int,vector<int> > grp;
int visited[1000];

void dfs(int no){
  visited[no]=1;
  for(int i=0;i<grp[no].size();i++){
    if(visited[grp[no][i]]==0){
      dfs(grp[no][i]);
    }
  }
}

int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    grp[a].pb(b);
    grp[b].pb(a);
  }
  if(m - (n-1)==1){
    int done = 1;
    for(int i=1;i<=n;i++){
      if(visited[i]==0 and done==1){
        dfs(i);
        done = 0;
      }
      else if(visited[i]==0 and done==0){
        cout<<"NO\n";
        return 0;
      }
    }
    cout<<"FHTAGN!\n";
    return 0;
  }
  else{
    cout<<"NO"<<endl;
  }
  return 0;
}
