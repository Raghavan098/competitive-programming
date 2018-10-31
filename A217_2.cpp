#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
map<int , vector<int> > graph;
vector<int> visited;
void dfs(int i){
  visited[i]=1;
  for(int j=0;j<graph[i].size();j++){
    if(visited[graph[i][j]]==0){
      dfs(graph[i][j]);
    }
  }
}
int main(){
  int n;
  cin>>n;
  vector< pair <int,int> > v;
  int x,y;
  for(int i=0;i<n;i++){
    cin>>x>>y;
    v.push_back(make_pair(x,y));
  }
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(v[i].first==v[j].first || v[i].second==v[j].second){
        graph[i].push_back(j);
        graph[j].push_back(i);
      }
    }
  }
  for(int i=0;i<n;i++){
    visited.push_back(0);
  }
  int count=0;
  for(int i=0;i<n;i++){
    if(visited[i]==0){
      count++;
      dfs(i);
    }
  }
  cout<<count-1<<endl;
  return 0;
}
