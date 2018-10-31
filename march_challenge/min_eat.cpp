#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

int n,h,arr[100009];

int main(){ _
  int t;
  cin>>t;
  while(t--){
    cin>>n>>h;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    sort(arr,arr+n);
    llt l,r,mid,temp,ans;
    l = 1;
    r = arr[n-1];
    ans = arr[n-1];
    while(l<=r){
      mid = (l+r)/2;
      temp = 0;
      for(int i=0;i<n;i++){
        temp+=ceil(arr[i]*1.0/mid);
      }
      if(temp<=h){
        ans = mid;
        r = mid-1;
      }
      else{
        l = mid+1;
      }
    }
    cout<<ans<<endl;
  }
  return 0;


}
