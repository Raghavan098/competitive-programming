#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

llt combi[10000];
long long binpow(long long val, long long deg, long long mod) {
        if (!deg) return 1 % mod;
        if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
        long long res = binpow(val ,deg >> 1, mod);
        return (res*res) % mod;
}
llt ncr(llt n,llt r){
  llt ans1 = combi[n];
  llt ans2 = (combi[n-r]*combi[r])%1000000007;
  ans2 = binpow(ans2,1000000007-2,1000000007);
  llt ans = (ans1*ans2)%1000000007;
  return ans;
}

llt n,m,arr[3000],ans,temp,tot;
int main(){ _
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>arr[i];
  }
  sort(arr,arr+m);
  llt curr = 1;
  combi[0] =1;
  for(int i=1;i<=n;i++){
    combi[i] = curr;
    curr = (curr*(i+1))%1000000007;
  }
  ans = 1;
  tot = arr[0]-1;
  for(int i=1;i<m;i++){
    temp = arr[i] - arr[i-1]-1;
    if(temp>0){
      ans*=(binpow(2,temp-1,1000000007));
      ans%=1000000007;
      // tr3(ans,temp,i);
      tot+=temp;
      ans=(((ans)%1000000007)*ncr(tot,temp))%1000000007;
      ans%=1000000007;
    }
    // tr3(ans,temp,tot);
  }
  tot+=(n-arr[m-1]);
  if(n-arr[m-1]>0){
    ans*=(ncr(tot,n-arr[m-1]));
    ans%=1000000007;
  }
  cout<<ans<<endl;
  return 0;
}
