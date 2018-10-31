#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

llt n,arr[3];
vector<llt> get_factors(llt n){
  vector<llt> v;
  for(llt i=1;i*i<=n;i++){
    if(n%i==0){
      if(n/i!=i){
        v.push_back(i);
        v.push_back(n/i);
      }
      else{
        v.push_back(i);
      }
    }
  }
  return v;
}

int main(){ _
  llt t;
  cin>>t;
  while(t--){
    cin>>n>>arr[0]>>arr[1]>>arr[2];
    sort(arr,arr+3);
    vector<llt> v;
    v = get_factors(n);
    sort(v.begin(),v.end());
    llt p,q,r;
    llt ans  = 0;
    set<vector<llt> > s;
    for(llt i=0;i<v.size();i++){
      for(llt j=0;j<v.size();j++){
        p = v[i];
        q = v[j];
        if(n%(p*q)==0){
          r = n/(p*q);
          if(p>=q and q>=r){
            s.insert({p,q,r});
            s.insert({q,p,r});
            s.insert({q,r,p});
            s.insert({p,r,q});
            s.insert({r,p,q});
            s.insert({r,q,p});
          }
        }
      }
    }
    for(auto &v : s){
      if(v[0] <= arr[0] and v[1] <= arr[1] and v[2] <= arr[2]){
        ans++;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
