#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
typedef pair<ll,ll> pll;
vector<pll> v[2];
#define MP make_pair
#define PB push_back
int main() {
  ll n,k; scanf("%lld%lld",&n,&k);
  for (ll i=0;i<n;i++) {
    ll x,t;scanf("%lld%lld",&x,&t);
    if (x<0) v[1].PB(MP(-x,t));
    else v[0].PB(MP(x,t));
  }
  ll last=0;
  ll final=0;
  for (ll z=0;z<2;z++) {
    sort(v[z].begin(),v[z].end());
    ll vsz=v[z].size();
    ll ovf=0;
    for (ll i=vsz-1;i>=0;i--) {
      ll x=v[z][i].first,t=v[z][i].second;
      ll from_overflow=min(ovf,t);
      t-=from_overflow; ovf-=from_overflow;
      ll trips=t/k;
      ll left=t%k;
      if(left) {
        trips++;
        ovf+=(k-left);
      }
      if (trips) chkmax(last,x);
      final+=trips*2*x;
    }
  }
  //final-=last;
  printf("%lld\n",final);
}