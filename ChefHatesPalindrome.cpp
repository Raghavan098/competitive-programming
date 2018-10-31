#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int t;
  cin>>t;
  while(t--){
    ll n,k;
    cin>>n>>k;
    if(k>2){
      cout<<"1 ";
      for(int i=0;i<n;i++){
        cout<<(char)(((i%k)%26+97));
      }
      cout<<endl;
    }
    else if(k==1){
      cout<<n<<" ";
      for(int i=0;i<n;i++){
        cout<<"a";
      }
      cout<<endl;
    }
    else if(k==2){
      if(n==1){
        cout<<"1 a";
      }
      else if(n==2){
        cout<<"1 ab";
      }
      else if(n==3){
        cout<<"2 aab";
      }
      else if(n==4){
        cout<<"2 aabb";
      }
      else if(n==5){
        cout<<"3 aaabb";
      }
      else if(n==6){
        cout<<"3 aaabbb";
      }
      else if(n==7){
        cout<<"3 aaababb";
      }
      else if(n==8){
        cout<<"3 aaababbb";
      }
      else{
        char thisarr[6];
        thisarr[0]='a';
        thisarr[1]='a';
        thisarr[2]='b';
        thisarr[3]='b';
        thisarr[4]='a';
        thisarr[5]='b';
        cout<<"4 ";
        for(int i=0;i<n;i++){
          cout<<thisarr[i%6];
        }
      }
      cout<<endl;
    }
  }
  return 0;
}
