#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
llt mod = 1000000007;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin>>n;

  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  if(n==1){
    cout<<1<<endl;
    return 0;

  }
  int maxlen = 2;
  int currlen = 2;
  for(int i=2;i<n;i++){
    // cout<<i<<endl;
    if(arr[i]== arr[i-1]+arr[i-2]){
      currlen++;
    }
    else{
      currlen=2;
    }
    if(currlen>maxlen){
      maxlen=currlen;
    }
  }
  cout<<maxlen<<endl;
  return 0;
}
