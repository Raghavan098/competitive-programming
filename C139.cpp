#include<bits/stdc++.h>
using namespace std;
int INF = 1000000000;
int main(){
  int n,m,x,y;
  cin>>n>>m>>x>>y;
  char arr[n][m];
  int white[m+1];
  int black[m+1];
  for(int i=0;i<n;i++){
    for(int j = 0;j<m;j++){
      cin>>arr[i][j];
    }
  }
  white[0] = 0;
  black[0] = 0;
  for(int i=0;i<m;i++){
    white[i+1]= 0;
    black[i+1] = 0;
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      white[i+1]+=(arr[j][i]=='.');
      black[i+1]+=(arr[j][i]=='#');
    }
    black[i+1]+=black[i];
    white[i+1]+=white[i];
  }
  int dp[2][m+1];
  dp[0][0] = 0;
  dp[1][0] = 0;
  for(int i=1;i<=m;i++){
    dp[0][i] = INF;
    dp[1][i] = INF;
  }
  for(int i=0;i<=m;i++){
    for(int a = x;a<=y;a++){
      if((i+a)>m){
        break;
      }
      dp[0][i+a] = min(dp[0][i+a],dp[1][i]+black[i+a]-black[i]);
      dp[1][i+a] = min(dp[1][i+a],dp[0][i]+white[i+a]-white[i]);
    }
  }
  // for(int i=0;i<m;i++){
  //   cout<<dp[1][i]<<" "<<dp[0][i]<<endl;
  // }
  cout<<min(dp[1][m],dp[0][m])<<endl;
  return 0;
}
