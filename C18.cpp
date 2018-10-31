#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int arr[n];
  int prix_sum[n+1];
  prix_sum[0] = 0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    prix_sum[i+1] = arr[i]+prix_sum[i];
  }
  int count = 0;
  for(int i=1;i<n;i++){
    if(prix_sum[i]==prix_sum[n] - prix_sum[i]){
      count++;
    }
  }
  cout<<count<<endl;
  return 0;
}
