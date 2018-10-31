#include <iostream>
#define ll long long
using namespace std;
ll power(int k){
  ll n=1;
  for(int i=1;i<=k;i++){
    n=n*10;
  }
  return n;
}
ll get_zeroes(ll n){
  ll count=0;
  while(n>0){
    if(n%10==0 && n>0){
      count++;
      n=n/10;
    }
    else{
      break;
    }
  }
  return count;
}
int main(){
  ll x;
  ll k;
  cin>>x>>k;
  ll y=x;
  if(x%2 ==1 && x%5!=0){
    cout<<x*power(k)<<endl;
    return 0;
  }
  while(get_zeroes(x)<k ){
    x+=y;
  }
  cout<<x<<endl;
  return 0;
}
