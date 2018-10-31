#include <iostream>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
char a[55][55];
bool seen[55][55];
void dfs(ll x, ll y) {
	if (a[x][y]=='W') return;
	if (seen[x][y]) return;
	seen[x][y]=true;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n,m; cin>>n>>m;
	for (ll x=0;x<=n+1;x++) for (ll y=0;y<=m+1;y++) a[x][y]='W';
	for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) {
		cin>>a[x+1][y+1];
	}
	ll ans=0;
	for (ll x=1;x<=n;x++) for (ll y=1;y<=m;y++) {
		if (a[x][y]=='L'&&!seen[x][y]) {dfs(x,y);ans++;}
	}
	cout<<ans<<endl;
}
