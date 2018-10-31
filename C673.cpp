#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<string.h>
#include<limits>
#include<queue>
using namespace std;
typedef long long int ll;
int main(){
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  ll n;
  cin>>n;
  ll arr[n];
  for(ll i=0;i<n;i++){
    cin>>arr[i];
  }
  ll ans[n];
  for(ll i =0;i<n;i++){
     ans[i]=0;
  }
  ll tmp[n];
  ll mx = 0;
  ll mxele = 0;
  for(ll i=0;i<n;i++){
    for(ll j =0;j<n;j++){
      tmp[j]=0;
    }
    mx = 0;
    mxele =0;
    for(ll j=i;j<n;j++){
      tmp[arr[j]-1]+=1;
      if(tmp[arr[j]-1]>mx){
        mx = tmp[arr[j]-1];
        mxele = j;
        ans[arr[j]-1]+=1;
      }
      else if(tmp[arr[j]-1]==mx){
        ans[min(arr[j],arr[mxele])-1]+=1;
        if(arr[mxele]>arr[j]){
          mxele = j;
        }
      }
      else{
        ans[arr[mxele]-1]+=1;
      }
    }

  }
  for(ll i =0;i<n;i++){
    cout<<ans[i]<<" ";
  }cout<<endl;
  return 0;
}
