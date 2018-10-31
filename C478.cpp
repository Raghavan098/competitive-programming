#include <bits/stdc++.h>
using namespace std;
bool equal(int *arr){
  if(arr[0]==arr[1] && arr[1]==arr[2]){
    return true;
  }
  else{
    return false;
  }
}
bool zero(int *arr){
  for(int i=0;i<2;i++){
    for(int j = i+1;j<3;j++){
      if(arr[i]==0 && arr[j]==0){
        return true;
      }
    }
  }
  return false;
}
int main(){
  int arr[3];
  cin>>arr[0]>>arr[1]>>arr[2];
  sort(arr,arr+3);
  reverse(arr,arr+3);
  int count=0;
  while(equal(arr)==false && zero(arr)==false){
    int x = min((arr[0]-arr[2])/2,arr[1]);
    if(x == 0){
      x =1;
    }
    arr[0]-=x*2;
    arr[1]-=x;
    cout<<arr[0]<<endl;
    if(arr[0]<0){
      arr[0]=0;
      arr[1]=0;
      break;
    }
    count+=x;
    sort(arr,arr+3);
    reverse(arr,arr+3);
  }
  if(zero(arr)==false){
    count+=arr[0];
  }
  cout<<count<<endl;
  return 0;
}
