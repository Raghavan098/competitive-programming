#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

llt a,b;
llt ans = 0;

int main(){
  cin>>b>>a;
  if(a==b){
    cout<<0<<endl;
  }
  int state = 0;
  for(llt i=60;i>=0;i--){
    if((((llt)1<<i)&a)>0 && (((llt)1<<i)&b)>0){
      if(state==1)
        ans+=(llt)1<<i;
    }
    if((((llt)1<<i)&a)==0 && (((llt)1<<i)&b)>0){
      ans+=(llt)1<<i;
    }
    if((((llt)1<<i)&a)>0 && (((llt)1<<i)&b)==0){
      state = 1;
      ans+=(llt)1<<i;
    }
    if((((llt)1<<i)&a)==0 && (((llt)1<<i)&b)==0){
      if(state==1){
        ans+=(llt)1<<i;
      }
    }
    // cout<<ans<<" "<<i<<" "<<(((llt)1<<i)&a)<<" "<<(((llt)1<<i)&b)<<endl;
  }
  cout<<ans<<endl;
  return 0;
}
