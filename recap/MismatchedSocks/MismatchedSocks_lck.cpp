#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int main() {
	ll n;cin>>n;
	ll largest=0,sum=0;
	for (ll i=0;i<n;i++) {
		ll x;cin>>x;
		largest=max(largest,x);
		sum+=x;
	}
	ll others=sum-largest;
	ll wasted=max(0ll, largest-others);
	cout<<(sum-wasted)/2<<endl;
}