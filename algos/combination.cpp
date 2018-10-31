#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll combi[1000006];
long long binpow(long long val, long long deg, long long mod) {
        if (!deg) return 1 % mod;
        if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
        long long res = binpow(val ,deg >> 1, mod);
        return (res*res) % mod;
}
ll ncr(ll n,ll r){
  ll ans1 = combi[n];
  ll ans2 = (combi[n-r]*combi[r])%1000000007;
  ans2 = binpow(ans2,1000000007-2,1000000007);
  ll ans = (ans1*ans2)%1000000007;
  return ans;
}

int main(){
  int n;
  n = 100;
  ll curr = 1;
  combi[0] =1;
  for(int i=1;i<=n;i++){
    combi[i] = curr;
    curr = (curr*(i+1))%1000000007;
  }
  ll a,b;
  while(true){
    cin>>a>>b;
    cout<<ncr(a,b)<<endl;
  }
  return 0;
}
