#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin>>n;
  ll arr[n];
  ll stck[n];
  for(int i=0;i<n;i++){
    stck[i] = 0;
    arr[i] = 0;
  }
  ll sum = 0;
  int x;
  int sz = 1;
  double ans;
  for(int i=0;i<n;i++){
    cin>>x;
    if(x==1){
      int a,t;
      cin>>a>>t;
      arr[a-1] += t;
      sum+=((ll)t*a);
    }
    else if(x==2){
      int a;
      cin>>a;
      stck[sz] = a;
      sz++;
      sum+=((ll)a);
    }
    else{
      arr[sz-2] += arr[sz-1];

      sum-=(ll)arr[sz-1];
      sum-=(ll)stck[sz-1];
      arr[sz-1]=0;
      sz--;
    }
    // for(double j = 0;j<sz;j++){
    //   cout<<arr[j]<<" "<<stck[j]<<endl;
    // }
    printf("%.6Lf\n", (ld)sum / sz);
    // cout<<<<endl;
  }
  return 0;
}
