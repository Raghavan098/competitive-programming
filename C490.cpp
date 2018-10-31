#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll power(ll k){
  ll ans=1;
  for(ll i =0;i<k;i++){
    ans*=10;
  }
  return ans;
}
int main(){
  string s;
  ll no1,no2;
  cin>>s;
  cin>>no1>>no2;
  ll l1[s.length()];
  ll l2[s.length()];
  ll k;
  ll curr = 0;
  for(ll i=0;i<s.length();i++){
    k = s[i]-'0';
    // cout<<k<<endl;
    curr = curr*10+k;
    curr = curr%no1;
    l1[i]=curr;
  }
  curr = 0;
  ll lne = 0;
  for(ll i=s.length()-1;i>=0;i--){
    k = s[i]-'0';
    curr+=k*(power(lne));
    lne+=1;
    curr = curr%no2;
    l2[i]=curr;
  }
  ll curri = -1;
  ll p =0;
  for(ll i =s.length()-2;i>=0;i--){
    if(l1[i]==0 && l2[i+1]==0){
      curri=i;
      break;
    }
    if(i!=0 && l2[i]==0 && l1[i-1]==0){
      p=1;
      curri = i;
      break;
    }
  }
  string a1="";
  string a2="";
  if(p==0){

    for(ll i=0;i<s.length();i++){
      if (i<=curri){
        a1+=s[i];

      }
      else{
        a2+=s[i];
      }
    }
  }
  else{
    for(ll i=0;i<s.length();i++){
      if (i<=curri-1){
        a1+=s[i];

      }
      else{
        a2+=s[i];
      }
    }
  }
  // cout<<a1<<" "<<a2<<endl;
  if (curri==-1 || a2[0]=='0'){
    cout<<"NO";
  }
  else{
    cout<<"YES"<<endl;
    cout<<a1<<endl;
    cout<<a2<<endl;
  }
  return 0;
}
