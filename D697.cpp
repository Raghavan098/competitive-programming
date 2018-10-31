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

int n,temp;
map<int,vector<int> >grp;
int children[200000];
int parent[200000];
lld ans[200000];
int visited[200000];

int dfs(int no){
  visited[no] = 1;
  int tt,ch = 0;
  for(int i=0;i<grp[no].size();i++){
    tt = grp[no][i];
    if(visited[tt]==0){
      ch+=dfs(tt);
    }
  }
  children[no] = ch;
  return ch+1;
}

void bfs(){
  queue<int> q;
  q.push(1);
  for(int i=1;i<=n;i++){
    visited[i] = 0;
  }
  visited[1] =1;
  int tt,t2;
  while(!q.empty()){
    tt = q.front();
    q.pop();
    for(int i=0;i<grp[tt].size();i++){
      t2 = grp[tt][i];
      if(visited[t2]==0){
        ans[t2] = 1+ans[tt]+((children[tt] - children[t2]-1)*1.0)/2;
        visited[t2] = 1;
        q.push(t2);
      }
    }
  }
}


int main(){
  cin>>n;
  for(int i=2;i<=n;i++){
    cin>>temp;
    grp[temp].pb(i);
    grp[i].pb(temp);
    parent[i] = temp;
  }
  dfs(1);
  ans[1] = 1.0;
  bfs();
  for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
  }cout<<endl;
  return 0;
}
