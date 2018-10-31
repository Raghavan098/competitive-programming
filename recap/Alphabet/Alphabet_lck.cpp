/*
length of string * alphabet size DP
dp[x][y]:= At index x, what is the mincost to get to alphabet y?
*/
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }

const ll mn=54;
string s;
ll f[mn][mn];

int main() {
   cin>>s;
   ll n=s.size();
   for (ll y=0;y<=26;y++) f[0][y]=y;
   for (ll x=0;x<n;x++) {
      ll c=s[x]-'a';
      for (ll y=0;y<=26;y++) {
         f[x+1][y]=f[x][y];
      }
      chkmin(f[x+1][c+1],f[x][c]);
      for (ll y=1;y<=26;y++) {
         chkmin(f[x+1][y],f[x+1][y-1]+1);
      }
   }
   cout<<f[n][26]<<endl;
}
