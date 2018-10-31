#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  pair<int,int> arr[n];
  int x;
  for(int i=0;i<n;i++){
    cin>>x;
    arr[i] = make_pair(x,i+1);
  }
  sort(arr,arr+n);
  int a[n];
  int b[n];
  int i=0;
  int j=0;
  for(int k=0;k<n;k++){
    if(k%2==0){
      a[i] = arr[k].second;
      i++;
    }
    else{
      b[j] = arr[k].second;
      j++;
    }
  }
  cout<<i<<endl;
  for(int k = 0;k<i;k++){
    cout<<a[k]<<" ";
  }
  cout<<endl;
  cout<<j<<endl;
  for(int k = 0;k<j;k++){
    cout<<b[k]<<" ";
  }cout<<endl;
  return 0;
}
