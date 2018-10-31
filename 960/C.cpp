#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
typedef long long llt;
typedef long double lld;
using namespace std;

llt x,d,arr[20000];
vector<llt> v,ans;

vector<llt> get(llt no){
  vector<llt> temp;
  llt curr;
  string s = "";
  while(no>0){
    if(no%2==1){
      s+="1";
    }
    else{
      s+="0";
    }
    no/=2;
  }
  curr = 0;
  for(llt i=0;i<s.size();i++){
    if(s[i]=='1'){
      temp.pb(curr);
    }
    curr++;
  }
  return temp;
}

int main(){
  cin>>x>>d;
  v = get(x);
  llt done  =0;
  for(llt i=0;i<v.size();i++){
    done+=pow(2,v[i])-1;
  }
  llt curr = 1;
  llt prev_curr;
  // for(int i=0;i<v.size();i++){
  //   cout<<v[i]<<" ";
  // }cout<<endl;
  for(llt i=0;i<v.size();i++){
    prev_curr = curr;
    for(llt j=0;j<v[i];j++){
      if(curr - prev_curr>=d){
        curr+=d;
        curr+=1;
        prev_curr = curr;
      }
      ans.pb(curr);
      // curr+=1;
    }
    curr+=d;
  }
  llt r = ans.size();
  curr+=1;
  // cout<<done<<endl;
  for(llt i=0;i<x - done;i++){
    ans.pb(curr);
    curr+=d;
  }
  if(ans.size()>10000){
    cout<<-1<<endl;
    return 0;
  }
  cout<<ans.size()<<endl;
  for(llt i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }cout<<endl;
  return 0;
}
