// here left side's size is n and right side's size is k make the graph only for the left the right is assigned automatically
// works in O(nm)
// http://e-maxx.ru/algo/kuhn_matching
// check E1139.cpp
int n, k;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;

bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main() {

	mt.assign (k, -1);
	for (int v=0; v<n; ++v) {
		used.assign (n, false);
		try_kuhn (v);
	}

	for (int i=0; i<k; ++i)
		if (mt[i] != -1)
			printf ("%d %d\n", mt[i]+1, i+1);
}
