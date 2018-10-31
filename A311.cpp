#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  llt a,b;
  cin>>a>>b;
  if(((a*(a-1))/2)<=b){
    cout<<"no solution"<<endl;
  }
  else{
    for(int i=0;i<a;i++){
      cout<<0<<" "<<i<<endl;
    }
  }
  return 0;
}
