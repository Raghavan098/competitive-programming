#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

llt n,arr[500],length;
llt visited[500];
vector<llt> lcm;
llt B;

void not_dfs(llt curr){
  for(llt i=0;i<=n;i++){
    visited[i] = 0;
  }
  vector<llt> to_do;
  while(visited[curr]==0){
    visited[curr] = 1;
    to_do.push_back(curr);
    curr = arr[curr];
  }
  llt check = 0;
  llt to_lcm = 0;
  llt to_max = 0;
  for(llt i=0;i<to_do.size();i++){
    if(to_do[i]==curr){
      check=1;
    }
    to_lcm+=(check);
    to_max+=(!check);
  }
  if(to_max>B){
    B = to_max;
  }
  lcm.push_back(to_lcm);
}
llt lcm_find(llt a,llt b){
  return (a*b)/__gcd(a,b);
}
int main(){ _
  cin>>n;
  arr[0] = 0;
  B = -1;
  for(llt i=0;i<n;i++){
    cin>>arr[i+1];
    visited[i] = 0;
  }
  visited[n] = 0;
  for(llt i=1;i<=n;i++){
    not_dfs(arr[i]);
  }
  llt A = 1;
  for(llt i=0;i<lcm.size();i++){
    A = lcm_find(A,lcm[i]);
  }
  // cout<<A<<" "<<B<<endl;
  cout<<B/A*A+A<<endl;
  return 0;
}
