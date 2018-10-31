#include<bits/stdc++.h>
using namespace std;
int n,m,h,v,arr[200][200],cum[200][200],tot,done,a,b,c,d;
char temp;

int main(){
  int t;
  cin>>t;

  for(int t1=0;t1<t;t1++){
    cin>>n>>m>>h>>v;
    tot = 0;
    for(int i=0;i<200;i++){
      for(int j=0;j<200;j++){
        arr[i][j] = 0;
        cum[i][j] = 0;
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        cin>>temp;
        arr[i][j] = (temp=='@');
        tot+=arr[i][j];
        cum[i][j] = arr[i][j]+cum[i-1][j]+cum[i][j-1] - cum[i-1][j-1];
      }
    }
    // cout<<"hello"<<endl;
    if(tot%((h+1)*(v+1))!=0){
      cout<<"Case #"<<t1+1<<":"<<" IMPOSSIBLE"<<endl;
      continue;
    }
    tot/=((h+1)*(v+1));
    // cout<<tot<<endl;
    done = 0;
    for(int i=1;i<n;i++){
      for(int j=1;j<m;j++){
        a = cum[i][j];
        b = cum[i][m] - cum[i][j];
        c = cum[n][j] - cum[i][j];
        d = cum[n][m] - cum[i][j] -b -c;
        // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<i<<" "<<j<<endl;
        if(a==b and b==c and c==d and a==tot){
          cout<<"Case #"<<t1+1<<":"<<" POSSIBLE"<<endl;
          done = 1;
          break;
        }
      }
      if(done==1){
        break;
      }
    }
    if(done==0){
      cout<<"Case #"<<t1+1<<":"<<" IMPOSSIBLE"<<endl;
    }
  }
  return 0;
}
