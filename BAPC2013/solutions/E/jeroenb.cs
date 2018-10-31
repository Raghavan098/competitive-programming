/*
 * @EXPECTED_RESULTS@: CORRECT
 * O(P + log N)
 */
using System;
using System.Collections.Generic;
using System.Linq;

/*
F(n+1) = G(n) + H(n)
G(n+1) = K * F(n) + H(n-1)
H(n+1) = F(n) + K * G(n)

F(n) = G(n-1) + H(n-1)
G(n) = K * F(n-1) + H(n-2)
H(n) = F(n-1) + K * G(n-1)

      Fn+1  Gn+1  Hn+1  Hn
Fn           K     1
Gn     1           K
Hn     1                1
Hn-1         1
*/


public class jeroenb
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

			// Find possible H0's
			int[,] matrixx = { 
				{ 0, Kx, 1, 0 },
				{ 1, 0, Kx, 0 },
				{ 1, 0, 0, 1 },
				{ 0, 1, 0, 0 }
			};
			matrixx = MatrixPower(matrixx, Nx-1);
			HashSet<int> posH0 = new HashSet<int>();
			for(int h0 = 0; h0 < P; h0++)
			{
				int ans = 0;
				ans = (ans + Ax * matrixx[0,0]) % P;
				ans = (ans + Bx * matrixx[1,0]) % P;
				ans = (ans + Cx * matrixx[2,0]) % P;
				ans = (ans + h0 * matrixx[3,0]) % P;
				if(ans == x)
					posH0.Add(h0);
			}

			HashSet<int> posY = new HashSet<int>();
			int[,] matrixy = { 
				{ 0, Ky, 1, 0 },
				{ 1, 0, Ky, 0 },
				{ 1, 0, 0, 1 },
				{ 0, 1, 0, 0 }
			};
			matrixy = MatrixPower(matrixy, Ny-1);
			foreach(int h0 in posH0)
			{
				int ans = 0;
				ans = (ans + Ay * matrixy[0,0]) % P;
				ans = (ans + By * matrixy[1,0]) % P;
				ans = (ans + Cy * matrixy[2,0]) % P;
				ans = (ans + h0 * matrixy[3,0]) % P;
				posY.Add(ans);
			}
			
			if(posY.Count == 1)
				Console.WriteLine(posY.First());
			else
				Console.WriteLine("UNKNOWN");
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
}