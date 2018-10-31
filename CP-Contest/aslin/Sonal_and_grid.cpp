#include <bits/stdc++.h>
using namespace std;
#define N 200100
#define INF 1000000007
#define MOD 1000000007
typedef long long int ll;
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pf(x) printf("%d\n",x);
#define pf2(x,y) printf("%d %d\n",x,y);
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z);
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tr(x) cout<<x<< endl;
#define tr2(x,y) cout<<x<<" "<<y<< endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(x,y,z,a) cout<<x<<" "<<y<<" "<<z<<  " " << a << " " << endl;
#define sz(x) ((int) (x).size())
ll power(ll x, ll y) { // power exponent
    if (y == 0) {
        return 1;
    }
    if (y & 1) {
        return power(x, y - 1) * x % MOD;
    } else {
        ll tmp = power(x, y / 2);
        return tmp * tmp % MOD;
    }
}
ll fact[N], rfact[N];
ll query(pair<int,int> p1, pair<int,int> p2){  // total ways from p1 cell  to p2 cell;
    ll x = abs(p1.fi-p2.fi),y=abs(p1.se-p2.se);
    ll inverse_fact=(1ll*rfact[x]*rfact[y])%MOD;
    ll comb = (1ll*fact[x+y]*inverse_fact)%MOD;
    return comb;
}
int main(){
    int m, l, i, j, q, n, k, x, y;
    fact[0] = 1;
    rfact[0] = 1;
    for (i = 1; i <N; i++) {
        fact[i] = (1ll*fact[i - 1] * i )% MOD;
        rfact[i] = power(fact[i], MOD - 2);
    }
    cin >> n >> m >> k;
    if(k){
        cin >> x  >> y;
    }
    ll total_ways=query(mp(1,1),mp(n,m));
    ll blocked_ways=0;
    if(k)
        blocked_ways=1ll*query(mp(1,1),mp(x,y))*query(mp(x,y),mp(n,m))%MOD;
    ll ans = (total_ways-blocked_ways+MOD)%MOD;
    cout << ans;
}
