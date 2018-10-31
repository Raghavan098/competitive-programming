#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mn=302;
const ll MOD=1000000007ll;
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
inline ll add(ll x,ll y) {return (x+y+MOD+MOD)%MOD;}
ll a[mn];
ll f[2][mn][2][mn][2];
ll _factorial[mn];
ll factorial(ll x) {
	if (x<0) return 1;
	else return _factorial[x];
}
int main() {
	_factorial[0]=1;
	for (ll i=1;i<mn;i++) {
		_factorial[i]=mul(_factorial[i-1],i);
	}
	ll n,k;
	scanf("%lld%lld",&n,&k);
	for (ll i=0;i<n;i++) scanf("%lld",&a[i]);
	sort(a,a+n);
	memset(f[0],0,sizeof f[0]);
	for (ll i=0;i<n;i++) f[0][i][1][0][0]=a[i];
	ll final=0;
	for (ll p=0;p<n+k;p++) {
		ll cur=p&1,nxt=cur^1;
		memset(f[nxt],0,sizeof f[nxt]);
		for (ll oalx=0;oalx<n;oalx++) {
			for (ll oaeqx=0;oaeqx<=1;oaeqx++) {
				for (ll oilx=0;oilx<n;oilx++) {
					for (ll oieqx=0;oieqx<=1;oieqx++) {
						ll gval=f[cur][oalx][oaeqx][oilx][oieqx];
						if (gval==0) continue;
						//printf("p: %lld. alx:%lld aeqx:%lld ilx:%lld ieqx:%lld gval:%lld\n",p,oalx,oaeqx,oilx,oieqx,gval);
						for (ll t=0;t<3;t++) {
							ll alx=oalx,aeqx=oaeqx,ilx=oilx,ieqx=oieqx;
							ll agx=n-p-alx-aeqx;
							ll val=f[cur][oalx][oaeqx][oilx][oieqx];
							if (p<n) {
								bool good=false;
								if (t==0&&alx>0) {
									// Take something < x
									val=mul(val,alx);
									alx--;
									ilx++;
									good=true;
								}
								else if (t==1&&aeqx>0) {
									val=mul(val,aeqx);
									aeqx--;
									ieqx++;
									good=true;
								}
								else if (t==2&&agx>0) {
									val=mul(val,agx);
									agx--;
									good=true;
									//igx++; Who cares?
								}
								if (!good) continue;
							}
							else if (t!=0) continue;
							//printf("Inter: %lld %lld %lld %lld. t:%lld\n",alx,aeqx,ilx,ieqx,t);
							if (p>=k-1) {
								if (ilx>0) ilx--;
								else if (ieqx>0) {
									ieqx--;
									// Add to final
									ll plus=mul(val,n+k-1-p);
									plus=mul(plus,factorial(n-p-1));
									//printf("val:%lld plus:%lld. %lld %lld.\n",val,plus,n+k-1-p,factorial(n-p-1));
									final=add(final,plus);
								}
								// else if (igx>0) igx--; Who cares?
							}
							f[nxt][alx][aeqx][ilx][ieqx]=add(f[nxt][alx][aeqx][ilx][ieqx],val);
							//printf("Add %lld to %lld %lld %lld %lld. t:%lld\n",val,alx,aeqx,ilx,ieqx,t);
						}
					}
				}
			}
		}
	}
	printf("%lld\n",final);
}
