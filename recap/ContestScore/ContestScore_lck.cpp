#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
#define PB push_back
int main() {
	ll n,k; scanf("%lld%lld",&n,&k);
	priority_queue<ll,vector<ll>,greater<ll> > pq;
	vector<ll> v;
	for (ll i=0;i<n;i++) {
		ll x; scanf("%lld",&x);
		pq.push(x);
		if (pq.size()>=k) {
			ll y=pq.top();
			pq.pop();
			v.PB(y);
		}
	}
	while(!pq.empty()) {
		ll y=pq.top(); pq.pop(); v.PB(y);
	}
	ll ans=0;
	for (ll i=0;i<n;i++) {
		ans+=v[i]*(n-i);
	}
	printf("%lld\n",ans);
}