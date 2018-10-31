/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;
using System.Collections.Generic;

public class jeroenb
{
	static int[] dr = { 0, 1, 0, -1 };
	static int[] dc = { 1, 0, -1, 0 };

	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0)
		{
			string[] parts = Console.ReadLine().Split();
			int h = int.Parse(parts[0]) + 2;
			int w = int.Parse(parts[1]) + 2;
			string[] grid = new string[h+1];
			grid[0] = new string('.', w);
			for(int i = 1; i < h - 1; i++)
				grid[i] = "." + Console.ReadLine() + ".";
			grid[h-1] = new string('.', w);
			
			List<int> startr = new List<int>();
			List<int> startc = new List<int>();
			startr.Add(0);
			startc.Add(0);
			for(int r = 0; r < h; r++)
			{
				for(int c = 0; c < w; c++)
				{
					if(grid[r][c] == '$')
					{
						startr.Add(r);
						startc.Add(c);
					}
				}
			}
			if(startr.Count != 3) throw new Exception("There should be exactly 2 prisoners.");
			int[,,] dist = new int[startr.Count,h,w];
			for(int i = 0; i < startr.Count; i++)
			{
				for(int r = 0; r < h; r++)
					for(int c = 0; c < w; c++)
						dist[i,r,c] = int.MaxValue / 4;
				bool[,] done = new bool[h,w];
				LinkedList<int> Q = new LinkedList<int>();
				Q.AddLast(0);
				Q.AddLast(startr[i]);
				Q.AddLast(startc[i]);
				while(Q.Count > 0)
				{
					int d = Q.First.Value; Q.RemoveFirst();
					int r = Q.First.Value; Q.RemoveFirst();
					int c = Q.First.Value; Q.RemoveFirst();
					if(r < 0 || r >= h || c < 0 || c >= w) continue;
					if(done[r,c]) continue;
					done[r,c] = true;
					dist[i,r,c] = d;
					if(grid[r][c] == '*') continue;
					for(int j = 0; j < 4; j++)
					{
						if(grid[r][c] == '#')
						{
							Q.AddLast(d+1);
							Q.AddLast(r+dr[j]);
							Q.AddLast(c+dc[j]);
						}
						else
						{
							Q.AddFirst(c+dc[j]);
							Q.AddFirst(r+dr[j]);
							Q.AddFirst(d);
						}
					}
				}
			}
			int ans = w * h;
			for(int r = 0; r < h; r++)
				for(int c = 0; c < w; c++)
					if(grid[r][c] != '*')
						ans = Math.Min(ans, dist[0,r,c] + dist[1,r,c] + dist[2,r,c] + (grid[r][c] == '#' ? 1 : 0));
			Console.WriteLine(ans);
		}
	}
}
