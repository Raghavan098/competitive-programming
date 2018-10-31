#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int l[4];
  int x=-1;
  for(int i=0;i<4;i++){
    cin>>l[i];
    if(x<l[i]){
      x = l[i];
    }
  }
  for(int i=1;i<=2*x;i++){
    for(int j=1;j<=2*x;j++){
      for(int k=1;k<=2*x;k++){
        if(i>=l[0] and 2*l[0]>=i and j>=l[1] and 2*l[1]>=j and k>=l[2] and 2*l[2]>=k and k>=l[3] and 2*l[3]>=k and 2*l[3]<i and 2*l[3]<j and i!=j and j!=k and i!=k and i>j and j>k){
          cout<<i<<endl<<j<<endl<<k<<endl;
          return 0;
        }
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}
