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

int n,arr[300000],ans[300000],visited[300000];
map<int,pair<int,int> > grp;

void do_bfs(int no){
  queue<int> q;
  pair<int,int> temp1;
  q.push(no);
  int temp;
  visited[1] = 1;
  visited[0] = 1;
  while(!q.empty()){

    temp = q.front();
    // tr(temp);
    q.pop();
    temp1 = grp[temp];
    ans[temp-1] = min(ans[temp-1],ans[temp]+1);
    ans[temp1.fi] = min(ans[temp1.fi],ans[temp]+1);
    ans[temp1.se] = min(ans[temp1.se],ans[temp]+1);
    // tr(ans[5]);
    if(visited[temp1.fi]==0 and temp1.fi<=n){
      visited[temp1.fi] =1;
      q.push(temp1.fi);
    }
    if(visited[temp1.se]==0 and temp1.se<=n){
      visited[temp1.se] =1;
      q.push(temp1.se);
    }
    if(visited[temp-1]==0 and temp-1>0){
      visited[temp-1] = 1;
      q.push(temp-1);
    }
  }
}

int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
    grp[i] = mp(arr[i],i+1);
    ans[i] = INT_MAX;
  }
  ans[1] = 0;
  do_bfs(1);
  for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
  }cout<<endl;
  return 0;
}
