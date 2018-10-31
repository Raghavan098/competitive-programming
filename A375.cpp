#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;
string s;
int cnt[10];
llt rem;
int main(){ _
  cin>>s;
  for(int i=0;i<10;i++){
    cnt[i]=0;
  }
  for(int i=0;i<s.size();i++){
    cnt[s[i]-'0']++;
  }
  cnt[9]--;
  cnt[8]--;
  cnt[6]--;
  cnt[1]--;
  rem = 0;
  int temp;
  for(int i=1;i<10;i++){
    while(cnt[i]>0){
      cout<<i;
      temp = rem;
      cnt[i]--;
      rem = rem*10;
      rem+=i;
      rem%=7;
    }
  }
  rem*=10000;
  rem%=7;
  string arr[24];
  arr[0] = "1869";
  arr[1] = "1968";
  arr[2] = "1689";
  arr[3] = "6891";
  arr[4] = "8691";
  arr[5] = "8916";
  arr[6] = "1896";
  arr[7] = "1869";
  cout<<arr[7 - rem];

  while(cnt[0]>0){
    cnt[0]--;
    cout<<0;
  }
  cout<<endl;
  return 0;
}
