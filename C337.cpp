#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
llt pow2(llt x){
  llt ans = 1;
  llt a = 2;
  llt b = x;
  while(b > 0)
  {
      if(b%2 == 1)
      {
          ans *= a;
          ans = ans%1000000009;
      }
      b /=2;
      a*=a;
      a = a%1000000009;
  }
  return ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  llt n,m,k;
  cin>>n>>m>>k;
  llt rem = n-m;
  llt n1 = n - n%k;
  llt a = n1 - k*(rem -1) - 1;
  if(a<0){
    a = 0;
  }
  llt ans;
  llt x = a/k;
  ans = ((((pow2(x+1)-2)%1000000009)*k)%1000000009 + m - (x*k)%1000000009)%1000000009;
  while(ans<0){
    ans+=1000000009;
  }
  cout<<ans<<endl;
}
