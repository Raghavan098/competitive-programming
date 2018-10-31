#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,p;
    cin>>n>>p;
    if(n==1){
      cout<<"impossible"<<endl;
    }
    else if(p==1){
      cout<<"impossible"<<endl;
    }
    else if(p==2 && n%2!=0){
      for(int i=0;i<n;i++){
        if(i%2==0){
          cout<<"a";
        }
        else{
          cout<<"b";
        }
      }cout<<endl;
    }
    else if(n%p==0 && p!=2){
      char arr[p];
      for(int i=0;i<p/2;i++){
        if(i%2 == 0){
          arr[i]='a';
          arr[p-i-1]='a';
        }
        else{
          arr[i]='b';
          arr[p-i-1]='b';
        }
      }
      if(p%2==1)
        arr[p/2]='b';
      for(int i=0;i<n;i++){
        cout<<arr[i%p];
      }
      cout<<endl;
    }
    else if((n-1)%p==0){
      char arr[p];
      for(int i=0;i<p/2;i++){
        if(i%2 == 0){
          arr[i]='a';
          arr[p-i-1]='a';
        }
        else{
          arr[i]='b';
          arr[p-i-1]='b';
        }
      }
      if(p%2==1)
        arr[p/2]='b';
      for(int i=0;i<n;i++){
        if(i<n/2){
          cout<<arr[i%p];
        }
        else if(i==n){
          cout<<"b";
        }
        else{
          cout<<arr[(i-1)%p];
        }
      }
      cout<<endl;
    }
    else{
      cout<<"impossible"<<endl;
    }
  }
  return 0;
}
