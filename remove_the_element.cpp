#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define M 1000000007
typedef long long llt;
typedef long double lld;
using namespace std;

llt t,n,arr[500000],ans,dp[500000];


int main(){
  cin>>t;
  dp[0]=0;
  dp[1]=1;
  for(int i=2;i<=100000;i++){
    dp[i] = (dp[i-1]+(dp[i-1]*(i-1))%M)%M;
  }
  // for(int i=0;i<10;i++){
  //   cout<<dp[i]<<" ";
  // }cout<<endl;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    sort(arr,arr+n);
    reverse(arr,arr+n);
    ans = 0;
    for(int i=0;i<n;i++){
      ans+=(arr[i]*dp[i+1])%M;
      ans%=M;
    }
    cout<<ans<<endl;
  }
  return 0;
}
