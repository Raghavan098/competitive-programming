#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
typedef long long llt;
typedef long double lld;
using namespace std;

int n,arr[200000];

int main(){
  cin>>n;
  if(n%4==0){
    for(int i=1;i<=n/2;i++){
      if(i%2==1){
        arr[n-i] = i;
      }
      else{
        arr[i-1] = i;
      }
    }
    for(int i=n;i>n/2;i--){
      if(i%2==0){
        arr[n-i+2] = i;
      }
      else{
        arr[i+1] = i;
      }
    }
    for(int i=1;i<=n;i++){
      cout<<arr[i]<<" ";
    }cout<<endl;
  }
  else if(n%4==1){
    for(int i=1;i<=n/2;i++){
      if(i%2==1){
        arr[n-i] = i;
      }
      else{
        arr[i-1] = i;
      }
    }
    for(int i=n;i>n/2+1;i--){
      if(i%2==0){
        arr[i+1] = i;

      }
      else{
        arr[n-i+2] = i;
      }
    }
    arr[n/2+1] = n/2+1;
    for(int i=1;i<=n;i++){
      cout<<arr[i]<<" ";
    }cout<<endl;
  }
  else{
    cout<<-1<<endl;
  }
  return 0;
}
