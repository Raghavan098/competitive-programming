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

struct planet{
  lld x,y,z;
};

lld graph[500][500];
lld shortest_path[500][500];
int n;

void floyd_warshall(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      shortest_path[i][j] = graph[i][j];
    }
  }
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(shortest_path[i][k]+shortest_path[k][j]<shortest_path[i][j]){
          shortest_path[i][j] = shortest_path[i][k]+shortest_path[k][j];
        }
      }
    }
  }
}

planet inp[100];

void solve(int test){
  map<string,int> mp;
  cin>>n;
  string temp,temp2;
  for(int i=0;i<n;i++){
    cin>>temp>>inp[i].x>>inp[i].y>>inp[i].z;
    mp[temp] = i;
  }
  lld temp3;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      temp3 = sqrt(pow((inp[i].x - inp[j].x),2)+pow((inp[i].y - inp[j].y),2)+pow((inp[i].z - inp[j].z),2));
      graph[i][j] = temp3;
      graph[j][i] = temp3;
    }
  }
  int w;
  cin>>w;
  for(int i=0;i<w;i++){
    cin>>temp>>temp2;
    graph[mp[temp]][mp[temp2]] = 0.0;
  }
  floyd_warshall();
  int q;
  cout<<"Case "<<test<<":"<<endl;
  cin>>q;

  for(int i=0;i<q;i++){
    cin>>temp>>temp2;
    cout<<"The distance from "<<temp<<" to "<<temp2<<" is ";
    cout<<(int)round(shortest_path[mp[temp]][mp[temp2]])<<" parsecs."<<endl;
  }
}

int main(){
  int t;
  cin>>t;
  for(int i=1;i<=t;i++){
    solve(i);
  }
}
