#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;
llt n,m,k;
char arr[3000][3000];
int main(){
  cin>>n>>m>>k;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>arr[i][j];
    }
  }
  llt ans = 0;
  if(n==1 and m==1){
    if(k==1 and arr[0][0]=='.'){
      cout<<1<<endl;
    }
    else{
      cout<<0<<endl;
    }
    return 0;
  }
  for(int i=0;i<n;i++){
    int count = 0;
    for(int j=0;j<m;j++){
      if(arr[i][j]=='.'){
        count++;
        if(count>=k){
          ans+=1;
        }
      }
      else{
        count = 0;
      }

    }
  }
  if(k!=1){
    for(int i=0;i<m;i++){
      int count = 0;
      for(int j=0;j<n;j++){
        if(arr[j][i]=='.'){
          count++;
          if(count>=k){
            ans+=1;
          }
        }
        else{
          count = 0;
        }

      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
