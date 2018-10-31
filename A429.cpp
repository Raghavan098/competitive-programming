#include<bits/stdc++.h>
using namespace std;
int arr[100010];
int corrc[100010];
int vist[100010];
map<int, vector <int> > graph;
int n;
int x,y;
int ans;
vector<int> sol;
void dfs(int i,int x,int y){
  // cout<<i<<" "<<x<<" "<<y<<endl;
  vist[i]=1;
  if(x!=-1){
    if(x%2==0){
      arr[i-1]^=1;
    }
  }
  if(y!=-1){
    if(y%2==0){
      arr[i-1]^=1;
    }
  }
  if(arr[i-1]!=corrc[i-1]){
    ans+=1;
    sol.push_back(i);
    int done = 0;
    if(x!=-1){
      if(x%2==0){
        x = -1;
        done=1;
      }
    }
    if(y!=-1){
      if(y%2==0 and done==0){
        y = -1;
        done = 1;
      }
    }

    if(x==-1 and done==0){
      x = 0;
      done = 1;
    }
    if(y==-1 and done==0){
      y =  0;
    }


  }
  if(x!=-1){
    x++;
  }
  if(y!=-1){
    y++;
  }
  for(int j = 0;j<graph[i].size();j++){
    if(vist[graph[i][j]]==0){
      dfs(graph[i][j],x,y);
    }
  }
}
int main(){
  cin>>n;
  for(int i=0;i<n-1;i++){
    cin>>x>>y;
    graph[y].push_back(x);
    graph[x].push_back(y);
  }
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  for(int i=0;i<n;i++){
    cin>>corrc[i];
    vist[i]=0;
  }
  vist[n] = 0;
  x = -1;
  y = -1;
  ans = 0;
  for(int i=1;i<=n;i++){
    if(vist[i]==0){
      dfs(i,x,y);
    }
  }
  cout<<ans<<endl;
  for(int i=0;i<ans;i++){
    cout<<sol[i]<<endl;
  }
  return 0;
}
