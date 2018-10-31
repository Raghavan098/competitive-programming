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
			int n = int.Parse(Console.ReadLine());
			string[] m = new string[n];
			for(int i = 0; i < n; i++)
				m[i] = Console.ReadLine();
			string D = Console.ReadLine();
			string X = Console.ReadLine();
			HashSet<char>[] map = new HashSet<char>[200];
			for(int i = 0; i < 200; i++)
				map[i] = new HashSet<char>();
			int ncan = 0;
			for(int i = 0; i < n; i++)
			{
				if(D.Length != m[i].Length) continue;
				char[] mapsto = new char[200];
				char[] mapsfrom = new char[200];
				bool ok = true;
				for(int j = 0; ok && j < D.Length; j++)
				{
					if(mapsto[m[i][j]] > 0 && mapsto[m[i][j]] != D[j])
						ok = false;
					if(mapsfrom[D[j]] > 0 && mapsfrom[D[j]] != m[i][j])
						ok = false;
					mapsto[m[i][j]] = D[j];
					mapsfrom[D[j]] = m[i][j];
				}
				if(ok)
				{
					ncan++;
					for(int j = 0; j < 200; j++)
						map[j].Add(mapsto[j] == 0 ? '?' : mapsto[j]);
				}
			}
			if(ncan == 0)
				Console.WriteLine("IMPOSSIBLE");
			else
			{
				int known = 0;
				char[] sure = new char[200];
				bool[] used = new bool[200];
				for (int i = 'a'; i <= 'z'; i++)
				{
					if (map[i].Count == 1 && map[i].First() != '?')
					{
						sure[i] = map[i].First();
						used[sure[i]] = true;
						known++;
					}
				}
				if (known == 25)
				{ // special case, now we know the last one too!
					for (int i = 'a'; i <= 'z'; i++)
						if (sure[i] == 0)
							for (sure[i] = 'a'; used[sure[i]]; sure[i]++) ;
				}

				for(int i = 0; i < X.Length; i++)
				{
					if (sure[X[i]] > 0)
						Console.Write(sure[X[i]]);
					else
						Console.Write('?');
				}
				Console.WriteLine();
			}
		}
	}
}
