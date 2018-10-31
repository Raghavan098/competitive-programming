// Solution to Going Round in Circles
// Author: Pieter Bootsma

// Time complexity: O(c * 2^n)
// Memory: O(c * 2^n)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: memoization

#include <iostream>
#include <cstdio>

using namespace std;

int N;
int B[20];
int P[20];

double mem[17][1<<16];

double prob(int to_convert, int henchmen, int money)
{
	if (to_convert == 0)
		return 1;
	if (mem[to_convert][henchmen] >= 0)
		return mem[to_convert][henchmen];
	
	double mx = 0;
	for (int i = 0; i < N; i++)
	{
		if (!(henchmen & (1 << i)) && (money >= B[i]))
		{
			double p = P[i] / 100.;
			double success = p * prob(to_convert - 1, henchmen | (1 << i), money - B[i]);
			double failed = (1 - p) * prob(to_convert, henchmen | (1 << i), money - B[i]);
			mx = max(mx, (success + failed));
		}
	}
	
	mem[to_convert][henchmen] = mx;
	
	return mx;
}

void dostep()
{
	int c,m;
	cin >> N >> c >> m;
	for (int i = 0; i < N; i++)
		cin >> B[i] >> P[i];
	
	for (int i = 0; i <= c; i++)
		for (int j = 0; j < 1<<N; j++)
			mem[i][j] = -1;
	
	printf("%.6f\n", prob(c, 0, m));
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	return 0;
}
