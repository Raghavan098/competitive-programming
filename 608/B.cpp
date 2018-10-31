#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

string a,b;
llt count1[200000],ans[200000],cp,count2[200000],final_ans;

int main(){
  cin>>a;
  cin>>b;
  if(b[0]=='1'){
    count1[0]=1;
    count2[0]=0;
  }
  else{
    count1[0]=0;
    count2[0]=1;
  }
  for(int i=1;i<b.size();i++){
    count1[i] = count1[i-1]+(b[i]=='1');
    count2[i] = count2[i-1]+(b[i]=='0');
  }
  if(a[0]=='1'){
    final_ans=count2[b.size()-a.size()];
  }
  else{
    final_ans=count1[b.size()-a.size()];
  }
  for(int i=1;i<a.size();i++){
    if(a[i]=='1'){
      final_ans+=count2[b.size()-a.size()+i] - count2[i-1];
    }
    else{
      final_ans+=count1[b.size()-a.size()+i] - count1[i-1];
    }
  }
  cout<<final_ans<<endl;
  return 0;
}
