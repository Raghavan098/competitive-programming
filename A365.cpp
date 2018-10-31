#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
llt mod = 1000000007;
bool check(llt no,llt k){
  int arr[k+1];
  for(int i=0;i<=k;i++){
    arr[i] =0;
  }
  while(no){
    if(no%10<=k){
      arr[no%10] = 1;
      no/=10;
    }
    else{
      no/=10;
    }
  }
  for(int i=0;i<=k;i++){
    if(arr[i]==0){
      return false;
    }
  }
  return true;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,k;
  cin>>n>>k;
  llt no;
  llt count =0;
  for(int i=0;i<n;i++){
    cin>>no;
    if(check(no,k)==true){
      count++;
    }
  }
  cout<<count<<endl;
  return 0;
}
