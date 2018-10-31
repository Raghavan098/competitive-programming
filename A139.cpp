#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int t;

  cin>>n;
  cin>>t;
  int arr[n][2];
  for(int i=0;i<n;i++){
    cin>>arr[i][0]>>arr[i][1];
  }
  int a[6];
  a[0] = t;
  a[1] = 7-t;
  a[2] = arr[0][0];
  a[3] = 7-arr[0][0];
  a[4] = arr[0][1];
  a[5] = 7-arr[0][1];
  int cannot = 7 - t;
  int q=-1,w=-1;
  int done  = 0;
  int yes = 0;
  for(int i=1;i<n;i++){
    done = 0;
    for(int j=1;j<=6;j++){
      if(arr[i][0]==j or 7-arr[i][0]==j or arr[i][1]==j or 7-arr[i][1]==j){
        continue;
      }
      else{
        if(w==-1){
          w = j;
        }
        else{
          q = j;
        }
      }

    }
    if(q==cannot or w==cannot){
      done = 1;
      q = -1;
      w = -1;
    }
    if(done ==0){
      yes = 1;
      break;
    }
  }
  if(yes==1){
    cout<<"NO"<<endl;
  }
  else{
    cout<<"YES"<<endl;
  }
  return 0;
}
