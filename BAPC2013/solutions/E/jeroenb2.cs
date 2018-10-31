/*
 * @EXPECTED_RESULTS@: CORRECT
 * O(log P + log N)
 */
using System;
using System.Collections.Generic;
using System.Linq;

public class jeroenb2
{
	static int P;

	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0)
		{
			P = int.Parse(Console.ReadLine());
			string[] parts = Console.ReadLine().Split();
			int Ax = int.Parse(parts[0]);
			int Bx = int.Parse(parts[1]);
			int Cx = int.Parse(parts[2]);
			int Kx = int.Parse(parts[3]);
			int Nx = int.Parse(parts[4]);
			parts = Console.ReadLine().Split();
			int Ay = int.Parse(parts[0]);
			int By = int.Parse(parts[1]);
			int Cy = int.Parse(parts[2]);
			int Ky = int.Parse(parts[3]);
			int Ny = int.Parse(parts[4]);
			int x = int.Parse(Console.ReadLine());

			// Do some magic with matrices
			int[,] matrixx = { 
				{ 0, Kx, 1, 0 },
				{ 1, 0, Kx, 0 },
				{ 1, 0, 0, 1 },
				{ 0, 1, 0, 0 }
			};
			matrixx = MatrixPower(matrixx, Nx-1);
			int vx = (Ax * matrixx[0,0] + Bx * matrixx[1,0] + Cx * matrixx[2,0]) % P;

			int[,] matrixy = { 
				{ 0, Ky, 1, 0 },
				{ 1, 0, Ky, 0 },
				{ 1, 0, 0, 1 },
				{ 0, 1, 0, 0 }
			};
			matrixy = MatrixPower(matrixy, Ny-1);
			int vy = (Ay * matrixy[0,0] + By * matrixy[1,0] + Cy * matrixy[2,0]) % P;

			// Special cornercase
			if(matrixx[3,0] == 0)
			{
				if(matrixy[3,0] == 0)
					Console.WriteLine(vy);
				else
					Console.WriteLine("UNKNOWN");
			}
			else
			{
				int h0 = ((x - vx + P) * PowMod(matrixx[3,0], P-2, P)) % P;
				Console.WriteLine((vy + h0 * matrixy[3,0]) % P);	
			}
		}
	}

	public static int[,] MatrixMultiply(int[,] mat1, int[,] mat2)
	{
		if (mat1.GetLength(1) != mat2.GetLength(0)) return null;
		int[,] ret = new int[mat1.GetLength(0), mat2.GetLength(1)];
		for (int i = 0; i < ret.GetLength(0); i++)
			for (int j = 0; j < ret.GetLength(1); j++)
				for (int k = 0; k < mat1.GetLength(1); k++)
					ret[i, j] = (ret[i, j] + mat1[i, k] * mat2[k, j]) % P;
		return ret;
	}

	public static int[,] MatrixPower(int[,] matrix, int p)
	{
		if (p == 0)
		{
			int[,] ret = new int[matrix.GetLength(0), matrix.GetLength(0)];
			for (int i = 0; i < matrix.GetLength(0); i++)
				ret[i, i] = 1;
			return ret;
		}
		else if (p == 1)
		{
			return matrix;
		}
		else
		{
			int[,] rec = MatrixPower(matrix, p / 2);
			int[,] ret = MatrixMultiply(rec, rec);
			if (p % 2 != 0)
				ret = MatrixMultiply(ret, matrix);
			return ret;
		}
	}

	static int PowMod(int a, int n, int m)
	{
		if(n == 0) return 1;
		if(n == 1) return a % m;
		int ans = PowMod(a, n / 2, m);
		ans = (ans * ans) % m;
		if(n % 2 > 0)
			ans = (ans * a) % m;
		return ans;
	}
}