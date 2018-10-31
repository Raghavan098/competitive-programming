/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;
using System.Collections.Generic;

public class jeroenb
{
	public static void Main(string[] args)
	{
		System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;
		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0)
		{
			int w = int.Parse(Console.ReadLine());
			int n = int.Parse(Console.ReadLine());
			int[] x = new int[n];
			int[] y = new int[n];
			int[] r = new int[n];
			for(int i = 0; i < n; i++)
			{
				string[] parts = Console.ReadLine().Split();
				x[i] = int.Parse(parts[0]);
				y[i] = int.Parse(parts[1]);
				r[i] = int.Parse(parts[2]);
			}
			double low = 0;
			double up = w;
			for(int times = 0; times < 50; times++)
			{ // 50 is more then enough to get the desired precision
				double act = (low + up) / 2;
				bool possible = true;
				bool[] done = new bool[n];
				Queue<int> Q = new Queue<int>();
				for(int i = 0; i < n; i++)
					if(x[i] - r[i] - act <= 0)
						Q.Enqueue(i);
				while(Q.Count > 0)
				{
					int cur = Q.Dequeue();
					if(done[cur]) continue;
					done[cur] = true;
					if(x[cur] + r[cur] + act >= w)
					{
						possible = false;
						break;
					}
					for(int i = 0; i < n; i++)
						if(!done[i] && Sqr(x[i]-x[cur])+Sqr(y[i]-y[cur]) <= Sqr(r[i]+r[cur]+act))
							Q.Enqueue(i);
				}
				if(possible)
					low = act;
				else
					up = act;
			}
			Console.WriteLine(low/2);
		}
	}
	
	private static double Sqr(double x)
	{
		return x * x;
	}
}