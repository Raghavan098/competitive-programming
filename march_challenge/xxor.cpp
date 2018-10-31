#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

llt n,q,arr[100009],l,r;
llt sum[100009][32];

llt pow(int a,int b){
  llt ans = 1;
  for(int i=0;i<b;i++){
    ans*=a;
  }
  return ans;
}

void get_binary(llt no,int ind){
  for(int i=0;i<32;i++){
    sum[ind][i] = 0;
  }
  int ptr = 0;
  while(no>0){
    if(no%2==1){
      sum[ind][ptr] = 1;
    }
    ptr++;
    no/=2;
  }
}


int main(){ _
  cin>>n>>q;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    get_binary(arr[i],i);
  }

  for(int i=1;i<n;i++){
    for(int j = 0;j<32;j++){
      sum[i][j]+=sum[i-1][j];
    }
  }

  while(q--){
    cin>>l>>r;
    l--;
    r--;
    llt temp[32];
    llt ans[32];
    for(int i=0;i<31;i++){
      ans[i] = 0;
      temp[i] = sum[r][i];
    }
    if(l>0){
      for(int i=0;i<31;i++){
        temp[i]-=sum[l-1][i];
      }
    }
    // for(int i=0;i<31;i++){
    //   cout<<temp[i]<<" ";
    // }cout<<endl;
    int zeroes,ones;
    int total = r - l+1;
    int temp1 = 0;
    for(int i= 0;i<31;i++){
      ones = temp[i];
      zeroes = total - temp[i];
      // cout<<ones<<" "<<zeroes<<" "<<temp1<<endl;
      if(zeroes>ones){
        ans[i] = 1;
        temp1 = zeroes/2;
      }
      else{
        temp1 = ones/2;
      }
    }
    // for(int i=30;i>=0;i--){
    //   cout<<ans[i]<<" ";
    // }cout<<endl;
    llt a = 0;
    for(int i=0;i<31;i++){
      a+=ans[i]*(pow(2,i));
    }
    cout<<a<<endl;
  }
  return 0;
}
