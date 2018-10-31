#include<bits/stdc++.h>
using namespace std;
typedef long long int llt;
int main(){
  llt t;
  cin>>t;
  while(t--){
    llt x,n;
    cin>>x>>n;
    llt s = ((n*(n+1))/2)-x;
    if(s%2==1){
      cout<<"impossible"<<endl;
    }
    else{
      s = s/2;
      llt p = 0;
      vector<llt> v;
      for(int i=n;i>1;i--){
        if(i!=x and (s - (p+i)!=x)){
          if(p+i<=s){
            p+=i;
            v.push_back(i);
          }
        }
      }
      // cout<<"hello";
      llt done = 0;
      if(p<s){
        if((s-p)!=x){
          v.push_back((s-p));
        }
        else{
          cout<<"impossible"<<endl;
          done = 1;
        }
      }
      llt ans[n+1];
      for(int i=0;i<n+1;i++){
        ans[i] = 0;
      }
      // for(int i=0;i<v.size();i++){
      //   cout<<v[i]<<" ";
      // }cout<<endl;
      if(done==0){
        for(int i=0;i<v.size();i++){
          ans[v[i]] = 1;
        }
        ans[x] = 2;
        for(int i=1;i<n+1;i++){
          cout<<ans[i];
        }
        cout<<endl;
      }

    }
  }
  return 0;
}
