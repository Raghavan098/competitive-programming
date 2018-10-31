#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
map<int,vector<int> > graph;
int cost[100100];
int ssc[100100];
int d[100100];
int u[100100];
#define mod 1000000007ll
bool stacked[100100];
int n;
stack<int>s;
int ticks;
int comps;
void tar(int i){
  u[i]=d[i]=++ticks;
  s.push(i);
  stacked[i] = true;
  for(int j=0;j<graph[i].size();j++){
    // cout<<graph[i].size()<<endl;
    int v = graph[i][j];
    if(d[v] == -1){
      tar(v);
      u[i] = min(u[i],u[v]);

    }
    else if(stacked[v]){
      u[i] = min(u[i],u[v]);
    }
  }
  if(d[i]==u[i]){
    comps++;
    int j = -1;
    do{
      j = s.top();
      s.pop();
      stacked[j] = false;
      ssc[j] = comps;
    }while(i!=j);
  }
}
void tarjan(){
  ticks = 0;
  comps = 0;
  for(int i=0;i<n;i++){
    d[i]=-1;
    ssc[i] = 0;
    u[i]= 0;
    stacked[i] = false;
  }
  for(int i=0;i<n;i++){
    // cout<<"helllo"<<endl;
    if(d[i]==-1)
      tar(i);
  }

}
int main(){

  cin>>n;
  for(int i = 0;i<n;i++){
    cin>>cost[i];
  }
  int m;
  cin>>m;
  int x,y;
  for(int i=0;i<m;i++){
    cin>>x>>y;
    x--;
    y--;
    graph[x].push_back(y);
  }
  tarjan();
  // for(int i=0;i<n;i++){
  //   cout<<ssc[i]<<endl;
  // }
  i64 min[n];
  i64 count[n];
  for(int i=0;i<n;i++){
    min[i] = 2000000000;
    count[i] = 0;
  }
  for(int i=0;i<n;i++){
    int c = ssc[i];
    int w = cost[i];
    if(w<min[c]){
      min[c] = w;
      count[c] = 1;
    }
    else if(w==min[c]){
      count[c]++;
    }
  }
  long long a = 0,b = 1;
  for(int i=1;i<=comps;i++){
    a+=min[i];
    b*=i64(count[i]);
    b%=mod;
  }
  cout<<a<<" "<<b<<endl;
  return 0;
}
