#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long int llt;
llt a, llt b;
llt ans(llt a){
  if(a<10){
    return a;
  }
  int digit =0;
  llt temp;
  int last = a%10;
  int first;
  while(temp>0){
    if(temp/10==0){
      first = temp%10;
    }
    temp/=10;
    digit++;
  }
  llt ans1 = pow(10,digit - 2) -1;
  llt k = 1;
  while(k<first){
    ans1+=pow(10,digit-2);
    k++;
  }
  if(last>first){
    ans1+=pow(10,digit - 2);
  }else{
    
  }
  return ans1;
}
int main(){
  ios::sync_with_stdio(false);
  cout<<ans(b) - ans(a-1)<<endl;
  return 0;
}
