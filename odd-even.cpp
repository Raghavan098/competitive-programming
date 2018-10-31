#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

int n,arr[500000],even[500000],odd[500000],diff[500000],ind[500000],ans[500000];

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  for(int i=0;i<n;i++){
    even[i] = 0;
    odd[i] = 0;
  }
  if(arr[0]%2==0){
    even[0]++;
  }
  else{
    odd[0]++;
  }
  for(int i=0;i<n;i++){
    even[i] = even[i-1];
    odd[i] = odd[i-1];
    if(arr[i]%2==0){
      even[i]++;
    }
    else{
      odd[i]++;
    }
  }
  for(int i=0;i<n;i++){
    ind[i] = -1;
    diff[i] = odd[i] - even[i];
  }
  map<int,int> ord;
  for(int i=n-1;i>=0;i--){
    if(ord.find(diff[i])==ord.end()){
      ord[diff[i]] = i;
    }
    else{
      ind[i+1] = ord[diff[i]];
      ord[diff[i]] = i;
    }
  }
  if(ord.find(0)!=ord.end()){
    ind[0] = ord[0];
  }
  ans[n-1] = 0;
  for(int i=n-2;i>=0;i--){
    if(ind[i]!=-1){
      if(ind[i]!=n-1){
        ans[i] = 1+ans[ind[i]+1];
      }
      else{
        ans[i] = 1;
      }
    }
    else{
      ans[i] = 0;
    }
  }
  llt total = 0;
  for(int i=0;i<n;i++){
    total+=ans[i];
  }
  cout<<total<<"\n";
  return 0;
}
