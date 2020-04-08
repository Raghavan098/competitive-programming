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


//------------------------------------------use anything that is easy--------------------------
typedef pair <ll, ll> pll;
 
const int N = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 42;
// p[i] = rank of ith suffix!!!!
 
struct SuffixArray {
  const int L;
  vector<int> s;
  vector<vector<int> > P;
  vector<pair<pair<int,int>,int> > M;
 
  SuffixArray(const vector<int> &s) : L(s.size()), s(s), P(1, vector<int>(L, 0)), M(L) {
    for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
    for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
      P.push_back(vector<int>(L, 0));
      for (int i = 0; i < L; i++)
             M[i] = make_pair(make_pair(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++)
             P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
    }
  }
 
  vector<int> GetSuffixArray() { return P.back(); }
  vector<int> GetInvSuffixArray() {
      vector<int> ans(s.size());
      auto p = GetSuffixArray();
      for (int i = 0; i < (int)s.size(); i++) {
          ans[p[i]] = i;
      }
      return ans;
  }
  // returns the length of the longest common prefix of s[i...L-1] and s[j...L-1]
  int LongestCommonPrefix(int i, int j) {
    int len = 0;
    if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
      if (P[k][i] == P[k][j]) {
        i += 1 << k;
        j += 1 << k;
        len += 1 << k;
      }
    }
    return len;
  }
};
 
vector<int> lcp_construction(vector<int> const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;
 
    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}