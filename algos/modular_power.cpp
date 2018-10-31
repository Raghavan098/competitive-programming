const ll M = 1e9 + 7;

ll poww(ll a, ll p) {
	if (!p) return 1;
	ll ret = poww(a, p >> 1);
	ret = (ret * ret) % M;
	if (p & 1LL) ret = (ret * a) % M;
	return ret;
}
