#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
llt x;
map<llt,llt> mp;
string s;
llt arr[4004];
llt temp;
llt ans;
llt n;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>x;
  cin>>s;
  n = s.size();
  arr[0] = 0;
  for(int i=0;i<n;i++){
    temp = s[i]-'0';
    arr[i+1] = arr[i] +temp;
  }
  // for(int i=0;i<=s.size();i++){
  //   cout<<arr[i]<<" ";
  // }cout<<endl;
  for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
      mp[arr[j] - arr[i-1]]+=1;
    }
  }
  ans = 0;
  for(map<llt,llt>::iterator it = mp.begin();it!=mp.end();it++){

    llt a = it->first;
    llt b = it->second;
    if(x==0 and a==0){
      ans+=((b*(n)*(n+1))/2);
    }
    // if(a!=0)
    //   cout<<a<<" "<<b<<" "<<x%a<<" "<<bool(mp.find(x/a)!=mp.end())<<endl;
    if(a!=0 and x%a==0 and mp.find(x/a)!=mp.end()){
      // cout<<(b*mp[x/a])<<endl;
      ans+=(b*mp[x/a]);
    }
  }
  cout<<ans<<endl;
  return 0;
}
