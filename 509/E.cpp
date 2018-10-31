#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

string s;
char vov[6] = {'A','E','I','O','U','Y'};
llt ps[500005],ans[500005],n;

bool chk(char a){
  for(int i=0;i<6;i++){
    if(vov[i]==a){
      return true;
    }
  }
  return false;
}

int main(){
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(chk(s[i])){
      ps[i]++;
    }
  }
  for(int i=1;i<s.size();i++){
    ps[i] = ps[i-1]+ps[i];
  }
  n = s.size();
  ans[1] = ps[n-1];
  ans[n] = ans[1];
  for(int i=2;i<n/2+1;i++){
    ans[i] = ans[i-1]+ps[n-i] - ps[i-2];
    ans[n-i+1] = ans[i];
  }
  if(n%2==1){
    ans[n/2+1] = ans[n/2]+ps[n/2] - ps[n/2-1];
  }
  lld final_ans = 0;
  for(int i=1;i<= n;i++){
    final_ans+=(ans[i]*1.0/i);
  }
  printf("%Lf\n",final_ans);
  return 0;
}
