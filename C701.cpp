#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
typedef long long llt;
typedef long double lld;
using namespace std;

int n,arr[100],dis,inp[200000][70],sub[70];
string s;

int bin(int l,int r){
  int mid,temp,ans;
  ans=-1;
  while(l<=r){
    mid = (l+r)/2;
    temp = 0;
    for(int i=0;i<58;i++){
      if(inp[mid][i]-sub[i]>0){
        temp++;
      }
    }
    if(temp<dis){
      l = mid+1;
    }
    else{
      ans = mid;
      r = mid-1;
    }
  }
  return ans;
}

int main(){
  cin>>n;
  cin>>s;
  for(int i=0;i<n;i++){
    arr[s[i]-'A']++;
  }
  for(int i=0;i<58;i++){
    if(arr[i]>0){
      dis++;
    }
  }
  // cout<<dis<<endl;
  // for(int i=0;i<n;i++){
  //   cout<<s[i]-'A'<<" ";
  // }cout<<endl;
  for(int i=0;i<n;i++){
    inp[i][s[i]-'A']++;
  }
  for(int i=1;i<n;i++){
    for(int j=0;j<58;j++){
      inp[i][j] += inp[i-1][j];
    }
  }
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<58;j++){
  //     cout<<inp[i][j]<<" ";
  //   }cout<<endl;
  // }
  int ans;
  int final_ans = INT_MAX;
  for(int i=0;i<n;i++){
    ans = bin(i,n-1);
    // cout<<i<<" "<<ans<<endl;
    if(ans!=-1){
      if(ans-i+1<final_ans){
        final_ans = ans-i+1;
      }
    }
    sub[s[i]-'A']++;
  }
  cout<<final_ans<<endl;
}
