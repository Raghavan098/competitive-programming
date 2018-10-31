#include <iostream>
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
const ll mn=55;
ll a[mn];
ll f[mn][2];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin>>n;
	for (ll i=0;i<n;i++) cin>>a[i];
	for (ll x=0;x<=n;x++) for (ll k=0;k<2;k++) f[x][k]=1;
	ll ans=0;
	for (ll x=0;x<n;x++) for (ll k=0;k<2;k++) {
		ll v=f[x][k];
		chkmax(ans,v);
		for (ll y=x+1;y<n;y++) {
			if (k==0&&a[y]>a[x]) chkmax(f[y][k^1],v+1);
			if (k==1&&a[y]<a[x]) chkmax(f[y][k^1],v+1);
		}
	}
	cout<<ans<<endl;
}
