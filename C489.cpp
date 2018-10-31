#include <bits/stdc++.h>
#define ll long long
using namespace std;
int power(int k){
  ll n=1;
  for(int i=1;i<=k;i++){
    n=n*10;
  }
  return n;
}
int main(){
  int n,m;
  cin>>n>>m;
  if(n*9<m || (m==0 && n!=1)){
    cout<<"-1 -1"<<endl;
  }
  else if(m==0 && n==1){
    cout<<"0 0";
  }
  else{
    int arr[n]={9};
    int minarr[n];
    for(int i=0;i<n;i++){
      arr[i]=9;
      minarr[i]=0;
    }
    minarr[n-1]=1;
    int sum = 9*n;
    int i=0;
    while(sum!=m){
      arr[i]-=1;
      sum-=1;

      if(arr[i]==0){
        i++;
      }
    }

    i=0;
    sum =1;
    // cout<<power(n-1)<<endl;
    while(sum!=m){
      minarr[i]+=1;
      sum+=1;
      if(minarr[i]==9){
        i++;
      }
    }
    for(int j=n-1;j>=0;j--){
      cout<<minarr[j];
    }
    cout<<" ";
    for(int j=n-1;j>=0;j--){
      cout<<arr[j];
    }
  }
  return 0;
}
