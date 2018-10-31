#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,p;
    cin>>n>>p;
    int e = 0;
    int h = 0;
    int k;
    for(int i=0;i<n;i++){
      cin>>k;
      if(k>= p/2){
        e++;
      }
      else if(k<=p/10){
        h++;
      }
    }
    if(e==1 && h==2){
      cout<<"yes";
    }
    else if(n>3){
      cout<<"no";
    }
    else{
      cout<<"no";
    }
    cout<<"\n";
  }
  return 0;
}
