#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
  ll n;
  cin>>n;
  ll arr[n];
  for(ll i=0;i<n;i++){
    cin>>arr[i];
  }
  sort(arr,arr+n);
  ll dp[n][2];
  dp[0][0]=arr[0];
  dp[0][1]=0;
  ll curr = arr[0];
  for(ll i=1;i<n;i++){
    if(arr[i]==curr){
      dp[i][0]=dp[i-1][0]+arr[i];
      dp[i][1]=dp[i-1][1];
    }
    else{
      if(arr[i]==curr+1){
        curr = arr[i];
        dp[i][0] = dp[i-1][1]+arr[i];
        dp[i][1] = max(dp[i-1][0],dp[i-1][1]);
      }
      else{
        curr = arr[i];
        dp[i][0]=max(dp[i-1][0],dp[i-1][1])+arr[i];
        dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
      }
    }
  }
  cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
  return 0;
}
