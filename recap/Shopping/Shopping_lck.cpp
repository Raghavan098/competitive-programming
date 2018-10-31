/*
n*log(n)*log(n)*log(max_value) where max_value is the maximum value in the array
Each time, you search for the next value in the array that is less or equal to v. Then you mod v by that value.
This is guaranteed to halve v.
*/
#include <iostream>
using namespace std;
typedef long long ll;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll mn=2e5+4;
const ll INF=5e18;
ll t[2 * mn];
ll n;
void build() {  // build the tree
  for (ll i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

ll query(ll l, ll r) {  // min on interval [l,r)
  ll res = INF;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res=min(res, t[l++]);
    if (r&1) res=min(res, t[--r]);
  }
  return res;
}
int main() {
   ll q; scanf("%lld %lld",&n,&q);
   for (ll i=0;i<n;i++) scanf("%lld",&t[i+n]);
   build();
   for (ll i=0;i<q;i++) {
      ll v,l,r; scanf("%lld %lld %lld",&v,&l,&r);
      l--;r--;
      while(l<=r) {
         ll imin=l,imax=r+1;
         while(imin<imax) {
            ll imid=(imin+imax)/2;
            if (query(l, imid+1) > v) imin=imid+1;
            else imax=imid;
         }
         if (imin<=r) {
            v=v%t[n+imin];
            l=imin+1;
         }
         else {
            break;
         }
      }
      printf("%lld\n",v);
   }
}