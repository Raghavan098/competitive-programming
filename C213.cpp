#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cstdio>
#include<math.h>
#include<cstdlib>
#include<map>
#include<utility>
#include<stack>

using namespace std;
#define ll long long int
vector <ll> v;
vector <ll> v1;
vector <ll> v2;
const int inf=100000005;

#define cincout ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define me1(a,i) memset(a,i,sizeof(a))
#define me2(a,i,n,m) memset(a,i,n*m*sizeof(a[0][0]))
#define mp make_pair
#define pb push_back
#define sortv(v) sort(v.begin(),v.end())
#define printv(n,v) for(int i=0;i<n;i++)  {cout<<v[i]<<" ";}

int main()
	{
	cincout;
	ll n,k,ans,maxc=1,co=1,j=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		{
		v.pb(0);
		cin>>v[i];
		}
	sortv(v);
	ans=v[0];
	for(int i=1;i<n;i++)
		{
		k-=(v[i]-v[i-1])*co;
		co++;
		while(k<0)
			{
			k+=v[i]-v[j];
			co--;
			j++;
			}
		if(co>maxc)
			{
			maxc=co;
			ans=v[i];
			}
		}
	cout<<maxc<<" "<<ans<<endl;
  	return 0;
  	}
