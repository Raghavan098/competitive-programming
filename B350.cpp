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

map<int,vector<int> > grp;
map<int,int> parent;
vector<int> hotel;
int type[200000],n,incoming[200000],visited[200000],ans[200000];

void dfs(int no){
  // tr(no);
  visited[no] = 1;
  int temp;
  for(int i=0;i<grp[no].size();i++){
    temp = grp[no][i];
    if(visited[temp]==0){
      dfs(temp);
    }
  }
  if(incoming[no]>1){
    ans[no] = 0;
    parent[no] = 0;
  }
  else{
    ans[no] = 1;
    parent[no] = 0;
    if(grp[no].size()==0){
      ans[no] = 1;
      parent[no] = 0;
    }
    else{
      for(int i=0;i<grp[no].size();i++){
        // tr(ans[grp[no][i]],ans[no]);
        if(ans[grp[no][i]]+1>ans[no]){
          ans[no] = ans[grp[no][i]]+1;
          parent[no] = grp[no][i];
        }
      }
    }
  }
  // tr(no,ans[no],parent[no],grp[no].size());


}

int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>type[i];
    if(type[i]==1){
      hotel.pb(i);
    }
  }
  // cout<<hotel<<endl;
  int temp;
  for(int i=1;i<=n;i++){
    cin>>temp;
    if(temp!=0){
      grp[i].pb(temp);
    }
    incoming[temp]++;
  }
  for(int i=0;i<hotel.size();i++){
    dfs(hotel[i]);
  }
  // for(int i=1;i<=n;i++){
  //   cout<<ans[i]<<" ";
  // }cout<<endl;
  int ind,max = -1;
  for(int i=0;i<hotel.size();i++){
    if(ans[hotel[i]]>max){
      max = ans[hotel[i]];
      ind = hotel[i];
    }
  }
  cout<<max<<endl;
  int curr = ind;
  vector<int> ansv;
  while(curr!=0){
    ansv.pb(curr);
    curr = parent[curr];
  }
  reverse(ansv.begin(),ansv.end());
  cout<<ansv<<endl;
  return 0;
}
