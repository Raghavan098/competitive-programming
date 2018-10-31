#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
llt n,m,k;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>n>>m>>k;
  llt l = 0;
  llt r = 250000000001;
  llt mid;
  llt temp;
  llt ans;
  while(l<=r){
    mid = (l+r)/2;
    temp = 0;
    for(int i=1;i<=n;i++){
      temp+=min(m,((mid-1)/i));
    }

    if(temp>k-1){
      // ans  = mid;
      r = mid-1;
    }
    else{
      ans = mid;
      l = mid+1;
    }
  }
  cout<<ans<<endl;
  return 0;
}
