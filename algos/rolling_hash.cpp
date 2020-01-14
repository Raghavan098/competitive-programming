struct RollingHash{
	vector<ll> pwr, hsh;
	ll A, M;
	int n;

	RollingHash(vector<int> s, ll _A, ll _M){
		n = s.size();
		pwr.resize(n+1); hsh.resize(n+1);

		A = _A, M = _M;

		pwr[0] = 1;
		for(int i = 1; i <= n; i++) pwr[i] = pwr[i-1] * A % M;

		hsh[0] = s[0] % M + 1;
		for(int i = 1; i < n; i++){
			hsh[i] = (hsh[i - 1] * A % M) + s[i] + 1; if(hsh[i] >= M) hsh[i] -= M;
		}
	}

	ll getHash(int x, int y){
		assert(x >= 0 and x < n and y >= 0 and y <= n);
		return (hsh[y] + M - ((x-1 >= 0)? hsh[x-1] * pwr[y-x+1] % M : 0)) % M;
	}
};
