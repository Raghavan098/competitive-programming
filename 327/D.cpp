#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

int n,m,i,j,k;
char arr[500][1000];
int visited[500][500];
map<pair<int , int>,vector<pair<int, int> > >graph;
vector<pair<int ,int > > this_component;
#define mp make_pair

void bfs(int i,int j){
  queue<pair<int, int> >q;
  q.push(mp(i,j));
  visited[i][j] = 1;
  pair<int,int> temp,temp2;
  while(!q.empty()){
    temp = q.front();
    this_component.push_back(temp);
    visited[temp.first][temp.second] = 1;
    q.pop();
    for(int k = 0;k<graph[temp].size();k++){
      temp2 = graph[temp][k];
      if(visited[temp2.first][temp2.second]==0){
        visited[temp2.first][temp2.second] = 1;
        q.push(temp2);
      }
    }

  }
}


int main(){ _
  cin>>n>>m;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      cin>>arr[i][j];
    }
  }
  for(i=0;i<n;i++){
    for(j = 0;j<m;j++){
      if(arr[i][j]=='.'){
        if(i>0 and arr[i-1][j]=='.'){
          graph[mp(i,j)].push_back(mp(i-1,j));
        }
        if(i<n-1 and arr[i+1][j]=='.'){
          graph[mp(i,j)].push_back(mp(i+1,j));
        }
        if(j>0 and arr[i][j-1]=='.'){
          graph[mp(i,j)].push_back(mp(i,j-1));
        }
        if(j<m-1 and arr[i][j+1]=='.'){
          graph[mp(i,j)].push_back(mp(i,j+1));
        }
      }
    }
  }
  for(i=0;i<n;i++){
    for(j = 0;j<m;j++){
      visited[i][j] = 0;
    }
  }
  vector<vector<int> > ans;
  int p1;
  for(i =0;i<n;i++){
    for(j =0;j<m;j++){
      if(visited[i][j]==0 and arr[i][j]!='#'){
        this_component.clear();
        bfs(i,j);
        p1 = this_component.size();
        for(k = p1-1;k>=0;k--){
          ans.push_back({1,this_component[k].first+1,this_component[k].second+1});
        }
        for(k =p1-1;k>0;k--){
          ans.push_back({2,this_component[k].first+1,this_component[k].second+1});
          ans.push_back({3,this_component[k].first+1,this_component[k].second+1});
        }
      }
    }
  }
  map<int , char> mp;
  mp[1] = 'B';
  mp[2] = 'D';
  mp[3] = 'R';
  printf("%d\n",ans.size());
  for(i=0;i<ans.size();i++){
    printf("%c %d %d\n",mp[ans[i][0]],ans[i][1],ans[i][2]);
  }
  return 0;
}
