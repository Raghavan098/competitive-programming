#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

int graph[500][500];
int shortest_path[500][500];
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
