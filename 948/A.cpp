#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

int n,m,p,q;
char arr[600][600];

int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>arr[i][j];
    }
  }
  int done=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]=='W'){
        for(int k=-1;k<=1;k++){
          for(int l=-1;l<=1;l++){
            p = i+k;
            q = j+l;
            if(abs(k)!=abs(l) and p<n and p>=0 and q<m and q>=0){
              if(arr[p][q]=='S'){
                cout<<"No"<<endl;
                return 0;
              }
            }
          }
        }
      }
    }
  }
  cout<<"Yes"<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]=='.'){
        cout<<'D';
      }else{
        cout<<arr[i][j];
      }
    }cout<<endl;
  }
  return 0;
}
