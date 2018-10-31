#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  llt t;
  cin>>t;
  for(int w = 0;w<t;w++){
    llt k;
    llt a,b;
    cin>>k>>a>>b;
    llt a1 = (a+b)*2;
    llt ans = a + b + ((a+b))%10;
    // cout<<ans<<"sad"<<endl;
    k = k-3;
    llt temp = k/4;
    llt arr[4];
    llt temp2 = a1/2;
    // a1%=10;
    llt sum = 0;
    // cout<<temp2<<endl;
    for(int i=0;i<4;i++){
      arr[i] = (temp2*2)%10;
      temp2 = arr[i];
      sum+=arr[i];
      // cout<<arr[i]<<" ";
    }
    ans+=((sum)*temp);
    llt rem = k%4;
    for(int i=0;i<rem;i++){
      ans+=arr[i];
    }
    // cout<<ans<<endl;
    if(ans%3==0){
      cout<<"YES\n";
    }
    else{
      cout<<"NO\n";
    }
  }
  return 0;
}
