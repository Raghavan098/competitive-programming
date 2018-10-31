#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grp;
vector<vector<int>> v;
vector<int> vsd;

void dfs(int n){
  vsd[n]=1;
  if(grp[n].size()==0){
    for(int i=1;i<k+1;i++){
      v[n][i]=0;
    }
  }
  for(int i=0;i<grp[n].size();i++){
    if(vsd[grp[n][i]]==0){
      dfs(grp[n][i]);
    }
  }
}
int main(){
  int n,k;
  cin>>n>>k;
  grp.resize(n+1);
  int x,y;
  for(int i=0;i<n;i++){
    cin>>x>>y;
    grp[x].push_back(y);
    grp[y].push_back(x);
  }
  vsd.resize(n+1);
  v.resize(n+1);
  for(int i=0;i<n+1;i++){
    vsd[i]=0;
  }
  dfs(0);
  return 0;
}
