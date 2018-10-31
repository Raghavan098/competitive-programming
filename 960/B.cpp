#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
typedef long long llt;
typedef long double lld;
using namespace std;

llt n,a[2000],b[2000],k1,k2,tot,maxp,maxd;
vector<llt > v;

int main(){
  cin>>n>>k1>>k2;
  for(llt i=0;i<n;i++){
    cin>>a[i];
  }
  for(llt i=0;i<n;i++){
    cin>>b[i];
  }
  tot = k1+k2;
  for(int i=0;i<n;i++){
    v.pb(abs(a[i]-b[i]));
  }
  for(int i=0;i<tot;i++){
    maxd = -1;
    for(int j=0;j<n;j++){
      if(v[j]>maxd){
        maxd = v[j];
        maxp = j;
      }
    }
    v[maxp] = abs(v[maxp]-1);
  }
  llt ans = 0;
  for(int i=0;i<n;i++){
    ans+=(llt)v[i]*(llt)v[i];
  }
  cout<<ans<<endl;
  return 0;
}
