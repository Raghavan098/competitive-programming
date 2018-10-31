#include <bits/stdc++.h>
using namespace std;
int n,m;
void solve(){
  if(1){
    if(m==n-1){
      cout<<"0";
      m-=1;
    }
    if(m==n || n == m-1){
      // cout<<"yes"<<n<<m;
      for(int i=0;i<n;i++){
        // cout<<i<<endl<<(i+1<n);
        cout<<"10";
        m-=1;
      }
      if(m==1){
        cout<<"1";
      }
    }

    else{
      if(n>ceil((m*1.0)/2)){
        cout<<"0";
        n-=1;
      }
      if(m==n){
        for(int i=0;i<n;i++){
          cout<<"10";
        }
      }
      else{
        for(int i=0;i<n-3;i++){
          if(m>1){
            cout<<"110";
            m-=2;
          }

        }
        n=3;


        if(m==2){
          cout<<"11";
        }
        else if(m==1){
          cout<<"1";
        }
      }
    }
  }
}
int main(){

  cin>>n>>m;
  if(n>(m+1) || ceil((m*1.0)/2)>(n+1)){
    cout<<"-1\n";
  }
  while(m>0 || n>0){
    solve();
  }
  return 0;
}
