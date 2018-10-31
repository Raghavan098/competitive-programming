#include<bits/stdc++.h>
typedef unsigned long long int llt;
using namespace std;
llt get_answer(llt n){
  return (n - 9*((n-1)/9));
}
llt fast_expo(llt x,llt y){
    llt res = 1;     // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = get_answer(res*x);

        // n must be even now
        y = y>>1; // y = y/2
        x = get_answer(x*x);  // Change x to x^2
    }
    return res;
}
llt n,e,a1,k,ans;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    cin>>n>>e;
    cout<<fast_expo(n,e)<<endl;
  }
  return 0;
}
