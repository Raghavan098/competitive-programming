#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;
int main(){
  llt n,m;
  cin>>n>>m;
  llt arr[m];
  for(int i=0;i<m;i++){
    cin>>arr[i];
  }
  llt curr = 1;
  llt ans = 0;
  for(int i=0;i<m;i++){
    if(arr[i]>curr){
      ans+=arr[i]-curr;
      curr = arr[i];
    }
    else if(arr[i]<curr){
      ans+=n + arr[i]-curr;
      curr = arr[i];
    }
    // cout<<ans<<" "<<curr<<endl;
  }
  cout<<ans<<endl;
  return 0;
}
