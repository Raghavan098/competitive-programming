#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;
llt x;
int main(){ _
  int t;
  cin>>t;
  while(t--){
    cin>>x;
    if(x==0){
      cout<<1<<" "<<1<<endl;
      continue;
    }
    int done = -1;
    for(int curr = 1;curr<=200000;curr++){
      lld root = sqrt((lld)((lld)curr*curr -(lld)x));
      if(root==floor(root) and root<=curr/2 and root!=0){
        // cout<<curr<<" "<<root<<endl;
        llt n = curr;
        llt m = curr/root;
        if(n*n - (n/m)*(n/m)== x){
          cout<<n<<" "<<m<<endl;
          done =1;
          break;
        }
      }
    }
    if(done==-1){
      cout<<-1<<endl;
    }
  }
}
