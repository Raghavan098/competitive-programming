#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long int lli;
lli mod = 1000000007;
lli power(lli a,lli b){
 lli ans = 1;
   while(b > 0)
   {
       if(b%2 == 1)
       {
           ans *= a;
           ans = ans%mod;
       }
       b /=2;
       a*=a;
       a = a%mod;
   }
   return ans;
}
int main(){
 ios::sync_with_stdio(false);
 string s;
 cin >> s;
 lli st = 0,i;
 for(i=0;i<s.size();i++){
   if(s[i]!='b'){
     st = i;
     break;
   }
 }
 lli acnt = 0;
 i = st;
 lli ans = 0;
 while(i<s.size()){
   if(s[i]=='a'){
     acnt++;
   }
   else{
     lli bcnt = 0;
     while(i<s.size()){
       if(s[i]=='b'){
         i++;
         bcnt++;
       }
       else{
         i--;
         break;
       }
     }
     ans+=((power(2,acnt)-1)*(bcnt))%mod;
     //ans+=((pow(2,acnt)-1)*(bcnt));
   }
   i++;
 }
 cout << ans%mod;
 return 0;
}
