/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;
using System.Collections.Generic;
using System.Linq;

public class jeroenb
{
	public static void Main(string[] args)
	{
		System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;

		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0)
		{
			string[] parts = Console.ReadLine().Split();
			n = int.Parse(parts[0]);
			int c = int.Parse(parts[1]);
			m = int.Parse(parts[2]);
			b = new int[n];
			p = new int[n];
			for(int i = 0; i < n; i++)
			{
				parts = Console.ReadLine().Split();
				b[i] = int.Parse(parts[0]);
				p[i] = int.Parse(parts[1]);
			}
			done = new bool[1<<n, c+1];
			mem = new double[1<<n, c+1];
			Console.WriteLine(rec(0, c));
		}
	}

	static int m, n;
	static int[] b, p;
	static bool[,] done;
	static double[,] mem;

	static double rec(int mask, int c)
	{
		if(c == 0) return 1;
		if(done[mask,c]) return mem[mask,c];
		done[mask,c] = true;
		int t = 0;
		for(int i = 0; i < n; i++)
			if((mask & (1<<i))>0)
				t += b[i];
		for(int i = 0; i < n; i++)
		{
			if((mask & (1<<i)) > 0) continue;
			if(t + b[i] > m) continue;
			double tp = rec(mask | (1<<i), c - 1) * p[i] / 100.0;
			tp += rec(mask | (1<<i), c) * (100 - p[i]) / 100.0;
			mem[mask,c] = Math.Max(mem[mask,c], tp);
		}
		return mem[mask,c];
	}
}


