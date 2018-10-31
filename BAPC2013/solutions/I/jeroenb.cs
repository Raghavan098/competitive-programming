/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;
using System.Collections.Generic;

public class jeroenb
{
	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0)
		{
			int n = int.Parse(Console.ReadLine());
			Dictionary<string, int> counts = new Dictionary<string, int>();
			for(int i = 0; i < n; i++)
			{
				string[] parts = Console.ReadLine().Split();
				if(!counts.ContainsKey(parts[1])) counts[parts[1]] = 1;
				else counts[parts[1]]++;
			}
			int ans = 1;
			foreach(int i in counts.Values) ans *= i + 1;
			Console.WriteLine(ans-1);
		}
	}
}