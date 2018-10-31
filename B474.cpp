#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  llt n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  llt st[n+1];
  st[0] = arr[0];
  llt ma = -1;
  for(int i=1;i<n;i++){
    st[i] = arr[i]+st[i-1];
    if (st[i]>ma){
      ma = st[i];
    }
  }
  llt k[ma+1];
  llt i =0;
  llt count = 1;
  for(int j = 0;j<=ma;j++){
    k[j] = count;
    if(j+1<ma and j+1>=st[i]){
      count+=1;
      i+=1;
    }
  }
  llt m;
  cin>>m;
  llt temp;
  for(int i=0;i<m;i++){
    cin>>temp;
    cout<<k[temp-1]<<endl;
  }
  return 0;
}
