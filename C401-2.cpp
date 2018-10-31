#include <bits/stdc++.h>
using namespace std;
int n,m;
int prev = 0;
int solve(){
  if(n==0 && m==1){
    cout<<"1";
    m-=1;
    return 0;
  }
  else if(n==0 && m==2){
    cout<<"11";
    m-=2;
    return 0;
  }
  if(m == n){
    cout<<"10";
    n-=1;
    m-=1;
  }
  else if(n-1 == m){
    cout<<"0";
    n-=1;
  }
  else if(n*2 +2 >= m){
    cout<<"110";
    n-=1;
    m-=2;
  }
}
int main(){

  cin>>n>>m;
  if(n>(m+1) || ceil((m*1.0)/2)>(n+1)){
    cout<<"-1\n";
  }
  else{
    while(m>0 || n>0){
      solve();
    }
  }
  return 0;
}
