#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;
llt n,m,k;
int sumOfDigits(int n){
  int ans = 0;
  while(n>0){
    ans+=n%10;
    n/=10;
  }
  return ans;
}
int main(){ _
  int n;
  cin>>n;
  int curr = 19;
  int pos = 9;
  for(int i = 0;i<n-1;i++){
    curr+=9;
    while(sumOfDigits(curr)!=10){
      curr+=9;
    }
  }
  cout<<curr<<endl;
  return 0;
}
