#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long int lli;
string func(string s){
 sort(s.begin(),s.end());
 reverse(s.begin(),s.end());
 return s;
}
int main(){
 ios::sync_with_stdio(false);
 string a,b;
 cin >> a >> b;
 if(a==b){
   cout << a;
   return 0;
 }
 if(b.size()>a.size()){
   cout << func(a);
   return 0;
 }
 int arr[10];
 for(int i=0;i<10;i++){
   arr[i] = 0;
 }
 for(int i=0;i<a.size();i++){
   arr[a[i]-'0']++;
 }
 string ans = "";
 int flg=0;
 for(int i=0;i<b.size();i++){
   if(flg==1){
     for(int j=9;j>=0;j--){
       if(arr[j]>0){
         ans+=(char)(j+'0');
         arr[j]--;
         break;
       }
     }
   }
   for(int j=b[i]-'0';flg==0 and j>=0;j--){
     if(arr[j]>0){
       ans+=(char)(j+'0');
       arr[j]--;
       if(j!=b[i]-'0'){
         flg = 1;
       }
       break;
     }
   }
 }
 cout << ans;
 return 0;
}
