#include <iostream>
#include <iomanip>
#include <math.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=1LL<<20LL;
ld logfact[mn+1];
ld C(ll n1, ll n2, ll k) {
	if (n1<k) return 0;
	return exp(logfact[n1]-logfact[n1-k]-(logfact[n2]-logfact[n2-k]));
}
ld ans[20];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ld lf=0.0;
	for (ll i=0;i<=mn;i++) {
		logfact[i]=lf;
		lf+=log(i+1);
	}
	ll k,r;
	cin>>k>>r;
	ll all=(1LL<<k)-1;
	ll good=(1LL<<k)-r;
	for (ll t=0;t<k;t++) {
		ll bot=1LL<<t;
		ans[t]=C(good,all,bot);
		all-=bot;
		good-=bot;
	}
	ld final=0.0;
	for (ll t=k-1;t>=0;t--) {
		final+=1;
		final*=ans[t];
	}
	cout<<fixed<<setprecision(5);
	cout<<final<<endl;
}
