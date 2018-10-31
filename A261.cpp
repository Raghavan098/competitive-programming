#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;
llt m,n,q[200000],arr[200000],req,ans,end,i,x,done;
int main(){ _
  cin>>m;
  for(i=0;i<m;i++){
    cin>>q[i];
  }
  cin>>n;
  for(i=0;i<n;i++){
    cin>>arr[i];
  }
  sort(q,q+m);
  sort(arr,arr+n);
  req = q[0];
  ans = 0;
  // x = n/(req+2);
  // // cout<<x<<endl;
  // for(int i = n-1;i>=n-x*req;i--){
  //   ans+=arr[i];
  // }
  // // cout<<ans<<" "<<ans<<endl;
  // done = x*req+2*x;
  // for(int i = x*2;i<n - x*req;i++){
  //   ans+=arr[i];
  // }
  // cout<<ans<<endl;
  i = n-1;
  while(i>=0){
    while(req--){
      ans+=arr[i];
      i--;
      if(i<0){
        break;
      }
    }
    req = q[0];
    i-=2;
  }
  cout<<ans<<endl;
  return 0;
}
