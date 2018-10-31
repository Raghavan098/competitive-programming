#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

llt n,arr[100005];
llt dp1[100005],dp2[100005];
int main(){ _

  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  sort(arr,arr+n);
  int min,t1,t2;
  int ptr = n;
  for(int i = 0;i<n;i++){
    if(arr[i]>500000){
      ptr = i;
      break;
    }
  }
  if(ptr==n){
    cout<<arr[n-1]-1<<endl;
  }
  else if(ptr==0){
    cout<<1000000  - arr[0]<<endl;
  }
  else{
    t1 = arr[ptr-1]-1;
    t2 = 1000000 - arr[ptr];
    cout<<max(t1,t2)<<endl;
  }
  return 0;
}
