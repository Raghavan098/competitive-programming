#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

llt n,arr[2005];
llt c1,c2;
llt pre[2005];

int main(){ _
  cin>>n;
  c1 = 0;
  c2 = 0;
  for(int i=0;i<=n;i++){
    pre[i] = 0;
  }
  arr[0] = 0;
  for(int i=0;i<n;i++){
    cin>>arr[i+1];
    if(arr[i+1]==-1){
      c1++;
    }
    else{
      pre[arr[i+1]] = 1;
    }
  }
  int n1,k1;
  n1 = 0;
  k1 = 0;
  for(int i=1;i<=n;i++){
    if(arr[i]!=-1 and pre[i]==0){
      n1 ++;
    }
    else if(arr[i]==-1 and pre[i]==0){
      k1++;
    }
  }
  llt combi[2001];
  combi[0] = 1;
  combi[1] = 1;
  for(int i=2;i<=n;i++){
    combi[i] = (combi[i-1]*i)%1000000007;
  }
  llt dp[n+10][n+10];
  for(int i=0;i<=n+9;i++){
  	for(int j=0;j<=n+9;j++){
  		dp[i][j] = 0;
  	}
  }
  for(int i=0;i<=n;i++){
    dp[i][0] = combi[i];
    dp[i][1] = (i*combi[i])%1000000007;
  }

  for(int j = 2;j<=n;j++){
    for(int i=0;i<=n;i++){
      dp[i][j] = ((i*dp[i][j-1])%1000000007 + ((j-1)*dp[i+1][j-2])%1000000007)%1000000007;
    }
  }
  cout<<dp[n1][k1]<<endl;
  return 0;
}
