#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include<string.h>
#define ll long long
using namespace std;
ll sgn(double a);
ll gcd(ll a,ll b);
ll mod_pow(ll x,ll n,ll mod); 			//快速幂 余数
const double e  = 2.718281828459;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=300005;

int a[105];
ll check(ll l,ll r,ll d)
{
	ll idx=0;
	for(ll i=l;i<=r;i++)
	{
		if(i%d==0)
		{
			idx=i;
			break;
		}
	}
	return idx;
}
int main()
{
	ll n,d,m,l;
	cin>>n>>d>>m>>l;
	ll ans=0;
	for(int i=0; i<n-1; i++)
	{
		if(check(l+1+i*m,m*(i+1)-1,d)!=0)
		{
			ans=check(l+1+i*m,m*(i+1)-1,d);
			break;
		}
	}
	if(ans==0)
	{
		ans=check(l+1+m*(n-1),1e18,d);
	}
	cout<<ans<<endl;
}
