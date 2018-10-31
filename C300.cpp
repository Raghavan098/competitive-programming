#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
llt a,b,n;
long long binpow(long long val, long long deg, long long mod) {
        if (!deg) return 1 % mod;
        if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
        long long res = binpow(val ,deg >> 1, mod);
        return (res*res) % mod;
}

bool best(llt sum){
  llt temp;
  // cout<<sum<<endl;
  while(sum>0){
    temp = sum%10;
    sum/=10;
    // cout<<temp<<" "<<sum<<endl;
    if(temp!=a and temp!=b){
      // cout<<endl;
      return false;
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>a>>b>>n;
  llt temp1=-1,temp2=-1;
  llt sum;
  int done = 0;
  llt combi[n+1];
  llt curr = 1;
  combi[0] =1;
  for(int i=1;i<=n;i++){
    combi[i] = curr;
    curr = (curr*(i+1))%1000000007;
  }
  llt final_ans = 0;
  for(int i=0;i<=n;i++){
    temp1 = i;
    temp2 = n-i;
    sum = a*temp1+b*temp2;
    if(best(sum)==true){

      done = 1;
      llt ans1 = combi[n];
      llt ans2 = (combi[n-temp1]*combi[temp1])%1000000007;
      ans2 = binpow(ans2,1000000007-2,1000000007);
      llt ans = (ans1*ans2)%1000000007;
      final_ans+=ans;
      final_ans%=1000000007;
    }
  }
  if(done==0){
    cout<<0<<endl;
  }
  else{
    cout<<final_ans<<endl;
  }
}
