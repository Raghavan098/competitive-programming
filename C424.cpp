#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  llt n;
  cin>>n;
  llt arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  llt k = 0;
  for(int i = 0;i<n;i++){
    k = k^arr[i];
  }
  llt temp = 0;
  llt xorarr[n];
  for(int i=0;i<n;i++){
    xorarr[i] = temp^(i+1);
    temp = temp^(i+1);
  }
  // for(int i=0;i<n;i++){
  //   cout<<xorarr[i]<<" ";
  // }cout<<endl;
  llt curr = 1;
  llt ans_arr[n];
  ans_arr[0] = 0;
  for(int i=1;i<n;i++){
    llt times = (n)/(i+1);
    // cout<<"times "<<times<<endl;
    if(times%2==1){
      times = xorarr[i-1];
    }
    else{
      times = 0;
    }
    llt rem = n%(i+1);
    // cout<<times<<endl;
    if(rem!=0)
      times^=xorarr[rem-1];
    // cout<<times<<" "<<rem<<endl;
    ans_arr[i] = times;
  }
  for(int i=0;i<n;i++){
    // cout<<ans_arr[i]<<" ";
    k= k^ans_arr[i];
  }
  // cout<<endl;
  cout<<k<<endl;
  return 0;
}
