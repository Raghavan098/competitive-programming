#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  llt n,l,r,q1,q2;
  cin>>n>>l>>r>>q1>>q2;
  llt arr[n+1];
  arr[0]= 0;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
  }
  llt lsum[n+1];
  llt rsum[n+1];
  lsum[0] = 0;
  rsum[n] = 0;
  for(int i = 1;i<=n;i++){
    lsum[i] = lsum[i-1]+arr[i];
  }
  for(int i=n-1;i>=0;i--){
    rsum[i] = rsum[i+1]+arr[i+1];
  }
  llt ans = 1e18;
  llt temp;
  // for(int i= 1;i<=n;i++){
  //   cout<<arr[i]<<" ";
  // }cout<<endl;
  // for(int i=0;i<=n;i++){
  //   cout<<lsum[i]<<" ";
  // }cout<<endl;
  // for(int i=0;i<=n;i++){
  //   cout<<rsum[i]<<" ";
  // }cout<<endl;
  for(int i=0;i<=n;i++){
    temp = l*lsum[i]+r*rsum[i];
    // cout<<temp<<endl;
    if(i<n-i){
      temp+=q2*(n-1-2*i);
    }
    else if(i>n-i){
      temp+=q1*(2*i-n-1);
    }
    // cout<<"temp "<<temp<<endl;
    ans = min(temp,ans);
  }
  cout<<ans<<endl;
  return 0;
}
