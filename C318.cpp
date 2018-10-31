#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

llt a,b,m,temp,ans;


int main(){
  cin>>a>>b>>m;
  if(a>b){
    temp = a;
    a = b;
    b = temp;
  }
  if(b>=m){
    cout<<0<<endl;
    return 0;
  }
  if(b<=0){
    cout<<-1<<endl;
    return 0;
  }
  if(a<0){
    ans+=-(a) / b ;
    a = (a%b+b)%b;
    if(a!=0){
      ans+=1;
    }
  }
  while(b<m){
    temp = a+b;
    a = min(b,temp);
    b = max(b,temp);
    ans+=1;
  }
  cout<<ans<<endl;
}
