#include<bits/stdc++.h>
using namespace std;
typedef long long int llt;
llt LCM2(llt a,llt b){
  return (a*b)/__gcd(a,b);
}
llt LCM(llt a,llt b,llt c){
  return LCM2(a,LCM2(b,c));
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  llt n;
  cin>>n;
  if(n>=3){
    if(n%2==1){
      cout<<n*(n-1)*(n-2)<<endl;
    }
    else{
      llt max1 = -1;
      llt temp;
      for(int i=max(llt(1),n-100);i<=n;i++){
        for(int j = i;j<=n;j++){
          for(int k = j;k<=n;k++){
            temp = LCM(i,j,k);
            if(temp>max1){
              max1 = temp;
            }
          }
        }
      }
      cout<<max1<<endl;
    }
  }
  else if(n==2){
    cout<<2<<endl;
  }
  else{
    cout<<1<<endl;
  }
  return 0;
}
