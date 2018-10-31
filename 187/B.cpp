#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

int n,m,r;
int arr[100][100][100];
int dp[100][100][100];
int shortest_path[100][100][100];

void floyd_warshall(int k){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      shortest_path[k][i][j] = arr[k][i][j];
    }
  }
  for(int k1=0;k1<n;k1++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(shortest_path[k][i][k1]+shortest_path[k][k1][j]<shortest_path[k][i][j]){
          shortest_path[k][i][j] = shortest_path[k][i][k1]+shortest_path[k][k1][j];
        }
      }
    }
  }
}

int main(){ _
  cin>>n>>m>>r;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        cin>>arr[i][j][k];
      }
    }
  }
  for(int i=0;i<m;i++){
    floyd_warshall(i);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      dp[0][i][j] = INT_MAX;
      for(int k=0;k<m;k++){
        if(shortest_path[k][i][j]<dp[0][i][j]){
          dp[0][i][j] = shortest_path[k][i][j];
        }
      }
    }
  }
  for(int k=1;k<=n;k++){
    for(int i = 0;i<n;i++){
      for(int j=0;j<n;j++){
        dp[k][i][j] = INT_MAX;
        for(int q=0;q<n;q++){
          if(dp[k][i][j]>dp[k-1][i][q]+dp[0][q][j]){
            dp[k][i][j] = dp[k-1][i][q]+dp[0][q][j];
          }
        }
      }
    }
  }
  int a,b,c;
  for(int i=0;i<r;i++){
    cin>>a>>b>>c;
    if(c>=n){
      cout<<dp[n][a-1][b-1]<<endl;
      continue;
    }
    cout<<dp[c][a-1][b-1]<<endl;
  }
  return 0;
}
