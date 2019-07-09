struct bit{		// use 1 based indices!!!
	int n; vector<int> tree;
	bit(int n) : n(n) { tree.assign(n + 1, 0); }
	int query(int l, int r) { return query(r) - query(l - 1); }
	int query(int r) {
		int s = 0;
		for(; r > 0; r -= (r & (-r))) s += tree[r];
		return s;
	}
	void update(int i, int v) {
		for(; i <= n; i += (i & (-i))) tree[i] += v;
	}
};
