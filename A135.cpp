#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin>>n;
  llt arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  sort(arr,arr+n);
  if(arr[n-1]!=1){
    arr[n-1] = 1;
    cout<<1<<" ";
    for(int i=0;i<n-1;i++){
      cout<<arr[i]<<" ";
    }cout<<endl;
  }
  else{
    arr[n-1]= 2;
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }cout<<endl;
  }
  return 0;
}
