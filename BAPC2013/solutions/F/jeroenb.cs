/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;

public class jeroenb
{
	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0)
		{
			string[] parts = Console.ReadLine().Split();
			int n = int.Parse(parts[0]);
			int m = int.Parse(parts[1]);
			for(int i = 0; i < m; i++)
				Console.ReadLine();
			Console.WriteLine(n-1);
		}
	}
}