#include <stdio.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
const ll mn=100000+4;
ll a[mn];
int main() {
	ll n,k,r; scanf("%lld%lld%lld",&n,&k,&r);
	for (ll x=0;x<=n;x++) a[x]=0;
	for (ll i=0;i<k;i++) {
		ll x; scanf("%lld",&x); a[x]=1;
	}
	ll ans=0;
	ll have=0;
	for (ll x=1;x<=r;x++) have+=a[x];
	for (ll x=1;x+r-1<=n;x++) {
		ll last=x+r-1;
		while(have<2){
			// The following while loop executes at most once
			// Otherwise we would have 2 cameras in the segment
			while(a[last]==1) last--;
			a[last]++;
			have++;
			ans++;
		}
		have+=a[x+r];
		have-=a[x];
	}
	printf("%lld\n",ans);
}