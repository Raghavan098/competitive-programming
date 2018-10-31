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

int n,a,b,prevp;
map<int, vector<int> > grp;
vector<pair<int,int> > rem,add;
int visited[2000];

void dfs(int no,int pnt){
  visited[no] = 1;
  int temp;
  for(int i=0;i<grp[no].size();i++){
    temp = grp[no][i];
    if(visited[temp]==1 && temp!=pnt){
      rem.pb(mp(no,temp));
    }
    else if(visited[temp]==0){
      dfs(temp,no);
    }
  }
}

int main(){
  cin>>n;
  for(int i=1;i<n;i++){
    cin>>a>>b;
    grp[a].pb(b);
    grp[b].pb(a);
  }
  prevp = 0;
  for(int i=1;i<=n;i++){
    if(visited[i]==0){
      add.pb(mp(prevp,i));
      dfs(i,0);
      prevp = i;
    }
  }
  // cout<<rem<<endl;
  set<pair<int,int > > done;
  pair<int,int> temp;
  cout<<add.size()-1<<endl;
  for(int i=0;i<rem.size();i++){
    temp = mp(rem[i].se,rem[i].fi);
    if(done.find(temp)==done.end()){
      done.insert(mp(temp.se,temp.fi));
    }
    else{
      rem[i].fi =-1;
    }
  }
  int j = 0;
  // cout<<rem<<endl;
  for(int i=0;i<add.size()-1 && add.size()>1;i++){
    while(rem[j].fi==-1){
      j++;
    }
    cout<<rem[j].fi<<" "<<rem[j].se<<" "<<add[i+1].fi<<" "<<add[i+1].se<<endl;
    j++;
  }
  // cout<<add<<endl;
  // cout<<rem<<endl;
  return 0;
}
