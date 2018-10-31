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
