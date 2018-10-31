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

int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};

string inp[2000];
int n,m;
int tf;
int final_ans;

int visited[2000][2000];
int ans[2000][2000];

bool check(int i,int j){
  if(i<0 or i>=n){
    return false;
  }
  if(j<0 or j>=m){
    return false;
  }
  if(inp[i][j]=='T'){
    return false;
  }
  return true;
}

void bfs(int ii,int jj){
  queue<pair<int,int> > q;
  q.push(mp(ii,jj));
  visited[ii][jj] = 1;
  int ti,tj;
  pair<int,int> temp;
  ans[ii][jj] = 0;
  while(!q.empty()){
    temp = q.front();
    ti = temp.fi;
    tj = temp.se;
    q.pop();
    if(inp[ti][tj]=='S'){
      tf = ans[ti][tj];
    }
    for(int i=0;i<4;i++){
      if(check(ti+x[i],tj+y[i]) and visited[ti+x[i]][tj+ y[i]]==0){
        visited[ti+x[i]][tj+y[i]] = 1;
        ans[ti+x[i]][tj+y[i]] = ans[ti][tj] + 1;
        q.push(mp(ti + x[i],tj + y[i]));
      }
    }
  }
}

int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>inp[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      ans[i][j] = 2000000;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(inp[i][j]=='E'){
        bfs(i,j);
        break;
      }
    }
  }
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<m;j++){
  //     cout<<ans[i][j]<<" ";
  //   }cout<<endl;
  // }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(inp[i][j]>='1' and inp[i][j]<='9'){
        if(ans[i][j]<=tf){
          final_ans+=inp[i][j] - '0';
        }
      }
    }
  }
  cout<<final_ans<<endl;
  return 0;
}
