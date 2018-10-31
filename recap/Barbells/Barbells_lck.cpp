/*
For each plate, bruteforce whether it's on the left side, right side, or not on any side.
Let R = B*(3^P)
Runtime is R*log(R)
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll mn=14;
ll b[mn],p[mn];
int main() {
   ll bn,pn; cin>>bn>>pn;
   for (ll i=0;i<bn;i++) cin>>b[i];
   for (ll i=0;i<pn;i++) cin>>p[i];
   ll zlim=1;
   for (ll i=0;i<pn;i++) zlim*=3;
   vector<ll> vans;
   for (ll tz=0;tz<zlim;tz++) {
      ll z=tz;
      ll l=0,r=0;
      for (ll i=0;i<pn;i++) {
         ll k=z%3;
         if (k==0) l+=p[i];
         else if (k==1) r+=p[i];
         z/=3;
      }
      if (l==r) {
         for (ll i=0;i<bn;i++) vans.PB(l+r+b[i]);
      }
   }
   sort(vans.begin(),vans.end());
   ll ans_size=vans.size();
   if (ans_size>0) printf("%lld\n",vans[0]);
   for (ll i=1;i<ans_size;i++) {
      if (vans[i]!=vans[i-1]) printf("%lld\n",vans[i]);
   }
}
