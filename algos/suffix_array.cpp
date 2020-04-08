/**
 * Description: Sort suffixes. 
 * Time: O(N\log N)
 * Source: SuprDewd, KACTL, majk, ekzhang (http://ekzlib.herokuapp.com)
 * Verification: 
	* http://usaco.org/index.php?page=viewproblem2&cpid=768
		* https://pastebin.com/y2Z9FYr6
	* https://open.kattis.com/problems/suffixsorting
	* https://codeforces.com/contest/1090/problem/J
 */

template<class T> struct RMQ { // floor(log_2(x))
	int level(int x) { return 31-__builtin_clz(x); } 
	vector<T> v; vector<vector<int>> jmp;
	int comb(int a, int b) { // index of min
		return v[a]==v[b]?min(a,b):(v[a]<v[b]?a:b); } 
	void init(const vector<T>& _v) {
        int n = _v.size();
		v = _v; jmp = {vector<int>(n)}; iota(all(jmp[0]),0);
		for (int j = 1; 1<<j <= n; ++j) {
			jmp.push_back(vector<int>(n-(1<<j)+1));
			for (int i = 0; i < (int)jmp[j].size(); i++)
                jmp[j][i] = comb(jmp[j-1][i], jmp[j-1][i+(1<<(j-1))]);
		}
	}
	int index(int l, int r) { // get index of min element
		int d = level(r-l+1);
		return comb(jmp[d][l],jmp[d][r-(1<<d)+1]); }
	T query(int l, int r) { return v[index(l,r)]; }
};

struct SuffixArray {
	string S; int N;
	RMQ<int> R; 
	void init(const string& _S) {
		S = _S; N = S.size();
		genSa(); genLcp(); 
        R.init(lcp);
	}
	vector<int> sa, isa; // sa[i] = index of the string for ith suffix in the suffix array
	void genSa() {
		sa.resize(N), isa.resize(N); iota(all(sa),0);
		sort(all(sa),[&](int a, int b) { return S[a] < S[b]; });
		for (int i = 0; i < N; i++) {
			bool same = i && S[sa[i]] == S[sa[i-1]];
			isa[sa[i]] = same ? isa[sa[i-1]] : i; 
		}
		for (int len = 1; len < N; len *= 2) { 
			// sufs currently sorted by first len chars
			vector<int> is(isa), s(sa), nex(N); iota(all(nex),0); 
			for (int i = -1; i < N; i++) { // rearrange sufs by 2*len
				int s1 = (i == -1 ? N : s[i])-len; 
				if (s1 >= 0) sa[nex[isa[s1]]++] = s1; 
			} 
			for (int i = 0; i < N; i++) { // update isa for 2*len
				bool same = i && sa[i-1]+len < N
							  && is[sa[i]] == is[sa[i-1]]
							  && is[sa[i]+len] == is[sa[i-1]+len]; 
				isa[sa[i]] = same ? isa[sa[i-1]] : i; 
			}
		}
	}
	vector<int> lcp;
	void genLcp() { // Kasai's Algo
		lcp = vector<int>(N-1); int h = 0;
		for (int i = 0; i < N; i++) if (isa[i]) {
			for (int j=sa[isa[i]-1]; j+h<N && S[i+h]==S[j+h]; h++);
			lcp[isa[i]-1] = h; if (h) h--; 
		}
		// if we cut off first chars of two strings with lcp h 
		// then remaining portions still have lcp h-1 
	}
	int getLCP(int a, int b) { // lcp of suffixes starting at a,b
		if (max(a,b) >= N) return 0;
		if (a == b) return N-a;
		int t0 = isa[a], t1 = isa[b];
		if (t0 > t1) swap(t0,t1);
		return R.query(t0,t1-1);
	}
};
