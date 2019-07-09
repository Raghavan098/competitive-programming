#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

long long pow(long long a, long long b, long long m)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans%m;
}

int add(int a, int b)
{
	int res = a + b;
	if(res >= MOD)
		return res - MOD;
	return res;
}

int mult(int a, int b)
{
	long long res = a;
	res *= b;
	if(res >= MOD)
		return res % MOD;
	return res;
}

int discreteLog(int a, int b, int m)
{
	a %= m, b %= m;
	if(b == 1)
		return 0;
	int cnt = 0;
	long long t = 1;
	for(int curg=__gcd(a, m);curg!=1;curg=__gcd(a, m))
	{
		if(b % curg)
			return -1;
		b /= curg, m /= curg, t = (t * a / curg) % m;
		cnt++;
		if(b == t)
			return cnt;
	}

	gp_hash_table<int, int> hash;
	int mid = ((int)sqrt(1.0 * m) + 1);
	long long base = b;
	for(int i=0;i<mid;i++)
	{
		hash[base] = i;
		base = base * a % m;
	}

	base = pow(a, mid, m);
	long long cur = t;
	for(int i=1;i<=mid+1;i++)
	{
		cur = cur * base % m;
		auto it = hash.find(cur);
		if(it != hash.end())
			return i * mid - it->second + cnt;
	}
    return -1;
}
