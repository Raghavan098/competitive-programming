#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  llt s,k;
  cin>>s>>k;
  if(s==1){
    cout<<2<<endl;
    for(llt i=0;i<1;i++){
      cout<<0<<" ";
    }
    cout<<1<<endl;
    return 0;
  }
  llt fib[10000];
  fib[0] = 0;
  fib[1] = 1;
  llt temp = 1;
  llt bb = -1;
  for(llt i =2;i<k;i++){
    fib[i] = temp;

    temp+=fib[i];
    if(temp>s){
      bb = i;
      // cout<<temp<<" "<<bb<<" "<<fib[i]<<endl;
      break;
    }
  }
  llt j,i,sum;
  if(bb==-1){
    fib[k] = temp;
    i = 0;
    j = k;
    sum = 2*temp;
    while(fib[j]<=s and j<1000){
      // cout<<fib[j]<<" ";
      j+=1;
      if(j-i+1>k){
        sum-=fib[i];
        i++;
      }
      fib[j] = sum;
      sum+=fib[j];
    }
  }
  else{
    j = bb+1;
  }
  // cout<<endl;
  // for(llt i=0;i<j;i++){
  //   cout<<fib[i]<<" ";
  // }
  // cout<<endl;
  sum = fib[j-1];
  i = j-2;
  llt ans[10000];
  llt h = 1;
  ans[0] = fib[j-1];
  while(sum<s){
    // cout<<sum<<" ";
    if(sum+fib[i]<=s){
      sum+=fib[i];
      ans[h] = fib[i];
      h++;
      i--;
    }
    else{
      i--;
    }
    if(sum==s){
      break;
    }
  }
  // while(sum!=s){
  //   ans[h]+=fib[i];
  //   h++;
  // }
  // cout<<i<<" "<<j<<endl;
  if(h==1){
    cout<<2<<endl;
    cout<<0<<" "<<ans[0]<<endl;
    return 0;
  }
  cout<<h<<endl;
  for(llt k = 0;k<h;k++){
    cout<<ans[k]<<" ";
  }cout<<endl;
  return 0;
}
