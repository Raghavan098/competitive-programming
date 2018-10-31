#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
llt a,b;
llt pow(llt a){
  llt ans = 1;
  for(int i=0;i<a;i++){
    ans*=10;
  }
  return ans;
}
llt solve(llt n){
  if(n<10){
    return n;
  }
  llt temp = n;
  llt count = 0;
  while(temp>0){
    temp/=10;
    count++;
  }
  count-=1;
  llt ans = 0;
  for(int i=count;i>=1;i--){
    temp = 9;
    for(int j = 0;j<i-2;j++){
      temp*=10;
    }
    ans+=temp;
  }
  llt ld,fd;
  fd = n%10;
  ld = (n%(pow(count+1)))/pow(count);
  if(fd>=ld){
    temp = ld-1;
    for(int j = 0;j<count-1;j++){
      temp*=10;
    }
    temp+=((n%pow(count))/10);
    temp+=1;
    return ans+temp;
  }
  else{
    temp = ld-1;
    for(int j=0;j<count-1;j++){
      temp*=10;
    }
    temp+=((n%pow(count))/10);
    return ans+temp;
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  llt a,b;
  cin>>a>>b;
  cout<<solve(b) - solve(a-1)<<endl;
  return 0;
}
