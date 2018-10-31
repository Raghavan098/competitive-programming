#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

llt init[50000],t,x,curr,total;

int main(){ _
  init[0] = 0;
  init[1] = 1;
  for(int i=1;i<=50000;i++){
    init[i] = (i*(i+1))/2;
  }
  cin>>t;
  while(t--){
    cin>>x;
    for(int i=1;i<=50000;i++){
      if(init[i]>x){
        curr = i;
        break;
      }
    }
    total = min(curr+init[curr]-x,curr-1+x-init[curr-1]);
    cout<<total<<endl;
  }
  return 0;
}
