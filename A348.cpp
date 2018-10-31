#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int max(int *arr,int n){
  int ma = -1;
  for(int i=0;i<n;i++){
    if(arr[i]>ma){
      ma = arr[i];
    }
  }
  return ma;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin>>n;
  // int temp;
  // cin>>temp;
  // int x;
  // priority_queue <int, vector<int>, greater<int> > pq;
  // for(int i=1;i<n;i++){
  //   cin>>x;
  //   pq.push(x);
  // }
  // int y = temp;
  // int b;
  // while(y>0){
  //   b = pq.top();
  //   b++;
  //   pq.pop();
  //   pq.push(b);
  //   y--;
  // }
  // int arr[n+1];
  // for(int i=0;i<n-1;i++){
  //   arr[i] = pq.top();
  //   pq.pop();
  // }
  // for(int i=0;i<n-1;i++){
  //   arr[i]-=temp;
  // }
  // cout<<temp+max(arr,n-1)<<endl;
  ll arr[n];
  ll sum = 0;
  ll m = -1;
  for(ll i=0;i<n;i++){
    cin>>arr[i];
    if(arr[i]>m){
      m = arr[i];
    }
    sum+=arr[i];
  }

  if(sum%(n-1)!=0){
    cout<<max(m,(sum/(n-1))+1);
  }
  else{
    cout<<max(m,(sum/(n-1)));
  }
  return 0;
}
