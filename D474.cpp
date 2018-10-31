#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
llt mod = 1000000007;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  llt t,k;
  cin>>t>>k;
  llt arr[100005][2];
  for(llt i=0;i<=k;i++){
    arr[i][0] =1;
    arr[i][1] = 0;
  }
  arr[0][0]= 0;
  arr[0][1] = 0;
  arr[k][0] = 2;
  arr[k][1] = 1;
  llt count = 1;
  if(k==1){
    count = 0;
  }
  for(llt i=k+1;i<=100002;i++){
    arr[i][0] = ((arr[i-k][0]*2)%mod+(count)%mod)%mod;
    arr[i][1] = arr[i-k][0];
    count+=(arr[i-k][0])%mod;
    count-=arr[i-k+1][1];
    while(count<0){
      count+=mod;
    }
    count%=mod;
    arr[i][0]%=mod;
    arr[i][1]%=mod;
  }
  // for(int i=1;i<=15;i++){
  //   cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
  // }cout<<endl;
  llt temp1,temp2;
  llt ans[100003];
  ans[0] = 0;
  for(llt i=1;i<100003;i++){
    ans[i] = (ans[i-1]+arr[i-1][0])%mod;
  }
  for(llt i=0;i<t;i++){
    cin>>temp1>>temp2;
    llt fina = ans[temp2+1] - ans[temp1];
    while(fina<0){
      fina+=mod;
    }
    cout<<fina<<endl;
  }
  return 0;
}
