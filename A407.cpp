#include<bits/stdc++.h>
typedef long long llt;
typedef long double lld;
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int done1 =-1;
  int done2 =-1;
  int x1,y1,x2,y2;
  lld temp;
  for(int i=1;i<=n;i++){
    temp = lld(sqrt(n*n - i*i));
    if(temp==llt(temp) and temp!=0){
      x1 = i;
      y1 = temp;
      for(int j=1;j<=m;j++){
        temp = lld(sqrt(m*m - j*j));
        // cout<<x2<<" "<<y2<<endl;
        if(temp==llt(temp) and temp!=0){
          x2 = j;
          y2 = temp;
          if(y1==y2){
            temp = x1;
            x1 = y1;
            y1 = temp;
            temp = x2;
            x2 = y2;
            y2 = temp;
          }
          if(y1*y2==x1*x2){
            cout<<"YES\n";
            cout<<"0 0\n";
            cout<<-x1<<" "<<y1<<endl;
            cout<<x2<<" "<<y2<<endl;
            return 0;
          }
        }
      }
    }
  }
  cout<<"NO\n";
  return 0;
}
