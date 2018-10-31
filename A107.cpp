#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
int n,m,a,b,mintill,start,w;
map<int, vector<pair<int,int> > > graph;
int visited[2000];
int start1[2000];
vector<vector<int> > ans;
void dfs(int i){
  visited[i] = 1;
  if(graph[i].size()==0){
    ans.push_back({start,i,mintill});
    return;
  }
  for(int j = 0;j<graph[i].size();j++){
    if(visited[graph[i][j].first]==0){
      mintill = min(mintill,graph[i][j].second);
      dfs(graph[i][j].first);
    }
    else{
      return;
    }
  }
}
int main(){
  cin>>n>>m;
  for(int i=0;i<=n;i++){
    start1[i] = 0;
  }
  for(int i=0;i<m;i++){
    cin>>a>>b>>w;
    start1[b]=1;
    graph[a].push_back(make_pair(b,w));
  }
  visited[0] = 0;
  for(int i=1;i<=n;i++){
    visited[i] = 0;
  }
  for(int i=1;i<=n;i++){
    if(visited[i]==0 and graph[i].size()>0 and start1[i]==0){
      mintill = INT_MAX;
      start = i;
      dfs(i);
    }
  }
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j]<<" ";
    }cout<<endl;
  }
  return 0;
}
