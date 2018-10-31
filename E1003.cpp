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

int n,d,k;
map<int,vector<int> > grp;
int visited[500500],height[500500];
int curr;
queue<int> q1,q2;
int h1,h2;

void fill(int no,int h){
  queue<int> q;
  q.push(no);
  visited[no] = 1;
  while(!q.empty()){
    int temp = q.front();
    q.pop();
    // tr(temp,height[temp],h,grp[temp].size());
    if(height[temp]==h){
      break;
    }
    int ha = grp[temp].size();
    for(int i=0;i<k-ha;i++){
      grp[temp].pb(curr);
      grp[curr].pb(temp);
      curr++;
      // tr(temp,curr);
      if(curr==n+1){
        return;
      }
    }
    for(int i=0;i<grp[temp].size();i++){
      if(visited[grp[temp][i]]==0){
        visited[grp[temp][i]] = 1;
        q.push(grp[temp][i]);
        height[grp[temp][i]] = height[temp]+1;
      }
    }
  }
}

void print_graph(){
  set<pair<ll,ll> >s;
  vector<pair<ll,ll> >v;
  for(ll i=1;i<=n;i++){
    for(auto j:grp[i]){
      if(s.find(mp(i,j))==s.end() and s.find(mp(j,i))==s.end()){
        v.pb(mp(i,j));
        s.insert(mp(i,j));
      }
    }
  }
  cout<<"YES\n";
  for(auto i:v){
    cout<<i.fi<<" "<<i.se<<endl;
  }
}

int main(){
  cin>>n>>d>>k;
  if(n<d+1){
    cout<<"NO"<<endl;
    return 0;
  }
  if(k==1 and n>2){
    cout<<"NO\n";
    return 0;
  }
  curr = 2;
  for(int i=1;i<=d;i++){
    grp[i].pb(i+1);
    grp[i+1].pb(i);
    curr++;
  }
  if(curr==n+1){
    print_graph();
    return 0;
  }
  int root = (d+1)/2 +1;
  // tr(root);
  curr = d+2;
  visited[root] = 1;
  height[root] = 1;
  q1.push(root-1);
  height[root-1] = 2;
  visited[root-1] = 1;
  if(k>1){
    q1.push(root+1);
    visited[root+1] = 1;
    height[root+1] = 2;
  }
  h1 = d/2 + 1;
  int he = grp[root].size();
  for(int i=0;i<k - he;i++){
    // tr(curr);
    if(height[root]==h1){
      cout<<"NO\n";
      return 0;
    }
    grp[root].pb(curr);
    grp[curr].pb(root);
    q1.push(curr);
    visited[curr] = 1;
    height[curr] = 2;
    curr++;
    if(curr==n+1){
      print_graph();
      return 0;
    }
  }
  // tr(curr,root);
  if(d%2==1){
    int temp = q1.front();
    // tr(temp);
    q2.push(temp);
    q1.pop();
    h2 = h1 +1;
  }
  while(!q1.empty()){
    int temp = q1.front();
    q1.pop();
    // tr(temp);
    fill(temp,h1);
    if(curr==n+1){
      print_graph();
      return 0;
    }
  }
  if(!q2.empty()){
    fill(q2.front(),h2);
    if(curr==n+1){
      print_graph();
      return 0;
    }
  }
  // print_graph();
  cout<<"NO\n";
  return 0;
}
