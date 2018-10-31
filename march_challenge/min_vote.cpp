#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

llt arr[100005];
llt cumu_sum[100005],cumu_sum2[100005];

int main(){ _
  llt t;
  cin>>t;
  while(t--){
    llt n;
    cin>>n;
    for(llt i=0;i<n;i++){
      cin>>arr[i];
    }
    cumu_sum[0] = arr[0];
    for(llt i=1;i<n;i++){
      cumu_sum[i] = cumu_sum[i-1]+arr[i];
    }
    cumu_sum2[0] = arr[n-1];
    for(llt i = 1;i<n;i++){
      cumu_sum2[i] = cumu_sum2[i-1] + arr[n-i-1];
    }

    llt l,r,mid,ans;
    llt temp;
    llt final_arr[100005],final_arr2[100005];
    for(int i=0;i<n;i++){
      final_arr[i] = 0;
      final_arr2[i]= 0;
    }
    for(llt i = 0;i<n-1;i++){
      l = i+1;
      r = n-1;
      ans = i;
      while(l<=r){
        mid = (l+r)/2;
        temp = cumu_sum[mid-1] - cumu_sum[i];
        if(temp<=arr[i]){
          // cout<<temp<<" "<<arr[mid]<<endl;
          ans = mid;
          l = mid+1;
        }
        else{
          r = mid-1;
        }
      }
      final_arr[i+1] +=1;
      if(ans+1<n){
        final_arr[ans+1]-=1;
      }
    }
    for(int i = 1;i<n;i++){
      final_arr[i] += final_arr[i-1];
    }
    for(llt i = 0;i<n;i++){
      l = i+1;
      r = n-1;
      ans = i;
      while(l<=r){
        mid = (l+r)/2;
        temp = cumu_sum2[mid-1] - cumu_sum2[i];
        if(temp<=arr[n-i-1]){
          ans = mid;
          l = mid+1;
        }
        else{
          r = mid-1;
        }
      }
      final_arr2[i+1] +=1;
      if(ans+1<n){
        final_arr2[ans+1]-=1;
      }
    }
    for(int i = 1;i<n;i++){
      final_arr2[i] += final_arr2[i-1];
    }
    for(int i=0;i<n;i++){
      cout<<final_arr[i]+final_arr2[n-i-1]<<" ";
    }cout<<endl;
  }
  return 0;
}
