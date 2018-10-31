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
		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0)
		{
			string[] parts = Console.ReadLine().Split();
			int C = int.Parse(parts[0]);
			int N = int.Parse(parts[1]);
			Dictionary<string,car> cars = new Dictionary<string,car>();
			for(int i = 0; i < C; i++)
			{
				parts = Console.ReadLine().Split();
				car c;
				c.p = long.Parse(parts[1]);
				c.q = long.Parse(parts[2]);
				c.k = long.Parse(parts[3]);
				cars[parts[0]] = c;
			}
			Dictionary<string,long> spies = new Dictionary<string,long>();
			Dictionary<string,string> hascar = new Dictionary<string,string>();
			HashSet<string> inconsistent = new HashSet<string>();
			for(int i = 0; i < N; i++)
			{
				parts = Console.ReadLine().Split();
				if(!spies.ContainsKey(parts[1]))
					spies[parts[1]] = 0;

				if(parts[2] == "p")
				{
					if(hascar.ContainsKey(parts[1]))
						inconsistent.Add(parts[1]);
					else
					{
						hascar[parts[1]] = parts[3];
						spies[parts[1]] += cars[hascar[parts[1]]].q;	
					}
				}
				else if(parts[2] == "r")
				{
					if(!hascar.ContainsKey(parts[1]))
						inconsistent.Add(parts[1]);
					else
					{
						spies[parts[1]] += cars[hascar[parts[1]]].k * long.Parse(parts[3]);
						hascar.Remove(parts[1]);
					}
				}
				else if(parts[2] == "a")
				{
					if(!hascar.ContainsKey(parts[1]))
						inconsistent.Add(parts[1]);
					else
					{
						spies[parts[1]] += (cars[hascar[parts[1]]].p * long.Parse(parts[3]) + 99) / 100; // trick for integer division rounded up
					}
				}
				else throw new Exception();
			}
			string[] spylist = spies.Keys.ToArray();
			Array.Sort(spylist);
			foreach(string spy in spylist)
			{
				Console.Write(spy);
				Console.Write(' ');
				if(inconsistent.Contains(spy) || hascar.ContainsKey(spy))
					Console.WriteLine("INCONSISTENT");
				else
					Console.WriteLine(spies[spy]);
			}
		}
	}

	struct car
	{
		public long p, q, k;
	}
}
