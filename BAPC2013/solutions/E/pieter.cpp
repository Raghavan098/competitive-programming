// @EXPECTED_RESULTS@: CORRECT

#include <iostream>

using namespace std;

void square(int in[4][4], int P)
{
	int tmp[4][4];
	
	for (int y = 0; y < 4; y++)
	for (int x = 0; x < 4; x++)
	{
		tmp[y][x] = 0;
		for (int z = 0; z < 4; z++)
		{
			tmp[y][x] += (in[y][z] * in[z][x]) % P;
		}
	}
	
	for (int y = 0; y < 4; y++)
	for (int x = 0; x < 4; x++)
	{
		in[y][x] = tmp[y][x] % P;
	}
}

void apply(int matrix[4][4], int values[4], int P)
{
	int tmp[4];
	
	for (int y = 0; y < 4; y++)
	{
		tmp[y] = 0;
		for (int z = 0; z < 4; z++)
		{
			tmp[y] += (matrix[y][z] * values[z]) % P;
		}
	}
	
	for (int y = 0; y < 4; y++)
	{
		values[y] = tmp[y] % P;
	}
}

int calc(int A, int B, int C, int K, int N, int H0, int P)
{
	int matrix[4][4] = {
		{0, 1, 1, 0},
		{K, 0, 0, 1},
		{1, K, 0, 0},
		{0, 0, 1, 0}
	};
	
	int values[4] = {A, B, C, H0};
	
	while (N > 0)
	{
		if ((N % 2) == 1) // M^{2N+1} * V
		{
			apply(matrix, values, P);
			N--;
		}
		else // M^{2N) * V
		{
			square(matrix, P);
			N /= 2;
		}
	}
	
	return values[0];
}

void dostep()
{
	int P;
	cin >> P;
	int Ax,Bx,Cx,Kx,Nx;
	cin >> Ax >> Bx >> Cx >> Kx >> Nx;
	int Ay,By,Cy,Ky,Ny;
	cin >> Ay >> By >> Cy >> Ky >> Ny;
	int x;
	cin >> x;
	
	if (Ny < 3)
	{
		cout << calc(Ay, By, Cy, Ky, Ny - 1, 0, P) << endl;
		return;
	}
	
	int y = -1;
	for (int H0 = 0; H0 < P; H0++)
	{
		if (calc(Ax, Bx, Cx, Kx, Nx - 1, H0, P) == x)
		{
			int y_cand = calc(Ay, By, Cy, Ky, Ny - 1, H0, P);
			if ((y >= 0) && (y != y_cand))
			{
				cout << "UNKNOWN" << endl;
				return;
			}
			y = y_cand;
		}
	}
	
	if (y < 0)
		cout << "UNKNOWN" << endl;
	else
		cout << y << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	return 0;
}
