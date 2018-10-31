// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <ctime>
using namespace std;

// limits
const int N = 16;
const int S = (1<<N);

// input
int n, c, m, b[N], p[N];

// recursion with memo
double memo[S][N];
double f(int cur_s, int cur_money, int cur_hits)
{
	if ( cur_hits >= c ) return 1.0;

	// check memo first (note: the state does not include cur_money since this is implied by cur_s)
	double* T = &memo[cur_s][cur_hits];
	if ( *T != -1 ) return *T;

	*T = 0;
	for(int i = 0, sp = 1; i < n; i++, sp <<= 1)
	{
		if ( sp & cur_s ) continue;
		int nxt_s = cur_s + sp;

		int nxt_money = cur_money - b[i];
		if ( nxt_money < 0 ) continue;

		// bribe i
		double p_i = f(nxt_s, nxt_money, cur_hits+1) * (p[i]/100.0);
		p_i += f(nxt_s, nxt_money, cur_hits) * ((100-p[i])/100.0);

		*T = max(*T,p_i);
	}
	return *T;
}

int main()
{
	double dt = clock();
	//cout.precision(10); cout << fixed;

	int runs = -1; cin >> runs;

	for(int run = 0; run < runs; run++)
	{
		// input
		cin >> n >> c >> m;
		for(int h = 0; h < n; h++) cin >> b[h] >> p[h];

		// reset memo
		for(int s = 0; s < S; s++)
			for(int i = 0; i < N; i++) 
				memo[s][i] = -1;

		// calculate answer
		double ans = f( 0, m, 0 );
		cout << ans << endl;
	}

	return 0;
}