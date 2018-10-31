#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  llt n,p;
  cin>>n>>p;
  string s;
  cin>>s;
  s = "##"+s;
  int done = 0;
  int point;
  for(int i=n+1;i>=2;i--){
    for(int j=s[i]-'a'+1;j<p;j++){
      if(i>0 and s[i-1]!=j+'a' and i>1 and s[i-2]!=j+'a'){
        s[i] = j+'a';
        done = 1;
        break;
      }
    }
    if(done == 1){
      point = i+1;
      break;
    }
    else{
      s[i] = '*';
    }
  }
  // cout<<s<<endl;
  if(done==0){
    cout<<"NO"<<endl;
  }
  else{
    // cout<<point<<endl;
    for(int i=point;i<n+2;i++){
      for(int j=0;j<p;j++){
        // cout<<j<<" "<<j+'a'<<endl;
        if(i>0 and s[i-1]!=j+'a' and i>1 and s[i-2]!=j+'a'){
          s[i] = j+'a';
          break;
        }
      }
    }
    for(int i=2;i<n+2;i++){
      cout<<s[i];
    }
    cout<<endl;
  }

  return 0;
}
