#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;
llt nodes[400000];
llt n,m;
map<int , vector<int> > graph;
llt visited[400000];
llt visit[400000];
llt curr[400000];
llt ans[400000][26];
bool dfs1(int i){
  visit[i] =1;
  curr[i] = 1;
  for(int j=0;j<graph[i].size();j++){
    if(curr[graph[i][j]]==1){
      return true;
    }
    if(visit[graph[i][j]]==0){
      if(dfs1(graph[i][j])==true){
        return true;
      }
    }
  }
  curr[i] = 0;
  return false;
}
bool check(){
  for(int i =1;i<=n;i++){
    if(visit[i]==0){
      if(dfs1(i)==true){
        return true;
      }
    }
  }
  return false;
}
void dfs(int i){
  visited[i] = 1;
  for(int d = 0;d<graph[i].size();d++){
    if(visited[graph[i][d]]==0){
      dfs(graph[i][d]);
    }
    for(int j = 0;j<26;j++){
      ans[i][j] = max(ans[i][j],ans[graph[i][d]][j]);
    }
  }
  ans[i][nodes[i]]++;
}
int main(){ _
  cin>>n>>m;
  char temp1;
  visited[0] =0;
  for(int i=1;i<=n;i++){
    cin>>temp1;
    nodes[i] = temp1-'a';
    visited[i] =0;
    visit[i] = 0;
    curr[i] = 0;
    for(int j = 0;j<26;j++){
      ans[i][j] = 0;
    }
  }
  int a,b;
  for(int i = 0;i<m;i++){
    cin>>a>>b;
    graph[a].push_back(b);
  }
  if(check()==true){
    cout<<-1<<endl;
    return 0;
  }
  for(int i = 1;i<=n;i++){
    if(visited[i]==0){
      dfs(i);
    }
  }
  int max = -1;
  for(int i=1;i<=n;i++){
    for(int j =0;j<26;j++){
      if(ans[i][j]>max){
        max = ans[i][j];
      }
    }
  }
  cout<<max<<endl;
  return  0;
}
