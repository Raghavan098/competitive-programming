#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int ans[5000000][12],k,l,r,x;

int get(int x){
  int p = 1;
  while(x>0){
    if(x%10!=0){
      p*=x%10;
    }
    x/=10;
  }
  return p;
}

int main(){
  int t;
  for(int i=0;i<10;i++){
    for(int j = 0;j<=10;j++){
      if(i==j){
        ans[i][j] = 1;
      }
      else{
        ans[i][j] = 0;
      }
    }
  }
  for(int i=10;i<1000001;i++){
    x = get(i);
    // cout<<i<<" "<<x<<endl;
    for(int j=0;j<=10;j++){
      ans[i][j] = ans[x][j];
    }
  }
  for(int i=1;i<1000001;i++){
    for(int j=0;j<=10;j++){
      ans[i][j]+=ans[i-1][j];
    }
  }
  // for(int i=0;i<=11;i++){
  //   for(int j=0;j<=10;j++){
  //     cout<<ans[i][j]<<" ";
  //   }cout<<endl;
  // }
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>l>>r>>k;

    // for(int i = l-1;i<=r;i++){
    //   // cout<<i<<" ";
    //   // for(int j=0;j<=10;j++){
    //   //   cout<<ans[i][j]<<" ";
    //   // }cout<<endl;
    // }
    // cout<<ans[l-1][k]<<" "<<ans[r][k]<<endl;
    cout<<ans[r][k] - ans[l-1][k]<<endl;
  }
  return 0;
}
