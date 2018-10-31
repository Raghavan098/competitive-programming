#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  llt n;
  cin>>n;
  if(n==1){
    cout<<1<<endl;
    return 0;
  }
  llt lp = 1;
  llt rp = n;
  while(rp>=lp){
    if(rp!=lp)
      cout<<lp<<" "<<rp<<" ";
    else{
      cout<<lp<<" ";
    }
    lp++;
    rp--;
  }
  cout<<endl;
  return 0;
}
