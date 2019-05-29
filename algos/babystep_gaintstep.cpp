namespace BSGS{
	int qpow(int a, int b, int p){
		int ans = 1, base = a;
		while (b){
			if (b & 1){
				(ans *= base) %= p;
			}
			(base *= base) %= p;
			b >>= 1;
		}
		return ans;
	}

	int inv(int x, int p){
		return qpow(x, p - 2, p);
	}

	map<int, int> tab;
	int bsgs(int a, int b, int p){
		int u = (int) sqrt(p) + 1;
		int now = 1, step;
		for (int i = 0; i < u; i++){
			int tmp = b * inv(now, p) % p;
			if (!tab.count(tmp)){
				tab[tmp] = i;
			}
			(now *= a) %= p;
		}
		step = now;
		now = 1;
		for (int i = 0; i < p; i += u){
			if (tab.count(now)){
				return i + tab[now];
			}
			(now *= step) %= p;
		}
		throw;
		return -1;
	}
}
