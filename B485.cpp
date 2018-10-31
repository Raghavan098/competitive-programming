#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;
int main(){ _
  llt n;
  cin>>n;
  llt maxx,minx,maxy,miny;
  maxx = -1000000002;
  maxy = -1000000002;
  minx = 1000000002;
  miny = 1000000002;
  llt tempx,tempy;
  for(int i=0;i<n;i++){

    cin>>tempx>>tempy;
    if(tempx>maxx){
      maxx = tempx;
    }
    if(tempy>maxy){
      maxy = tempy;
    }
    if(tempx<minx){
      minx = tempx;
    }
    if(tempy<miny){
      miny = tempy;
    }
  }
  llt k = max(maxx - minx,maxy- miny);
  cout<<k*k<<endl;
  return 0;
}
