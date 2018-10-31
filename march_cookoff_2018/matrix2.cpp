#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

int t,arr[200][200],n,m;

int main(){ _
  cin>>t;
  while(t--){
    cin>>n>>m;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>arr[i][j];
      }
    }
    if(arr[0][0]==-1){
      arr[0][0] = 1;
    }
    for(int i=1;i<m;i++){
      if(arr[0][i]==-1){
        arr[0][i] = arr[0][i-1];
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(arr[i][j]==-1 and j>0){
          arr[i][j] = max(arr[i][j-1],arr[i-1][j]);
        }
        else if(arr[i][j]==-1 and j==0){
          arr[i][j] = arr[i-1][j];
        }
      }
    }
    int done = 0;
    for(int i =0;i<n;i++){
      for(int j=1;j<m;j++){
        if(arr[i][j]<arr[i][j-1]){
          done = 1;
          break;
        }
      }
      if(done==1){
        break;
      }
    }
    for(int i=0;i<m;i++){
      for(int j=1;j<n;j++){
        if(arr[j][i]<arr[j-1][i]){
          done = 1;
          break;
        }
      }
      if(done==1){
        break;
      }
    }
    if(done==0){
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          cout<<arr[i][j]<<" ";
        }cout<<endl;
      }
    }
    else{
      cout<<-1<<endl;
    }
  }
  return 0;
}
