#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
const llt MOD = 1000000007;
using namespace std;

llt bpow(llt x, llt v) {
	if (v == 0)
		return 1 % MOD;

	if (v % 2 == 1)
		return (x * bpow(x, v - 1)) % MOD;

	llt r = bpow(x, v / 2);

	return (r * r) % MOD;
}
int main(){
  vector<llt> cbt;
  int n,x;
  llt sum,count1;
  cin>>n>>x;
  sum = 0;
  vector<llt> arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
    sum+=arr[i];
    sum%=MOD;
  }

  // sort(arr.begin(),arr.end());
  for(int i=0;i<n;i++){
    cbt.push_back(sum - arr[i]);
  }
  sort(cbt.rbegin(),cbt.rend());
  llt temp;
  while(true){
    temp = cbt[cbt.size()-1];
    count1 = 0;
    while(cbt.size()>0 and cbt[cbt.size()-1]==temp){
      count1+=1;
      cbt.pop_back();
    }
    if(count1%x==0){
      count1/=x;
      for(int i=0;i<count1;i++){
        cbt.push_back(temp+1);
      }
    }
    else{
      temp = min(temp,sum);
      cout<<bpow(x,temp)<<endl;
      return 0;
    }
  }
  return 0;
}
