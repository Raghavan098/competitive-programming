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
			int n = int.Parse(parts[0]);
			int m = int.Parse(parts[1]);
			int t = int.Parse(parts[2]);
			parts = Console.ReadLine().Split();
			int s = int.Parse(parts[0]) - 1;
			int g = int.Parse(parts[1]) - 1;
			int h = int.Parse(parts[2]) - 1;
			int[] a = new int[m];
			int[] b = new int[m];
			int[] d = new int[m];
			for(int i = 0; i < m; i++)
			{
				parts = Console.ReadLine().Split();
				a[i] = int.Parse(parts[0]) - 1;
				b[i] = int.Parse(parts[1]) - 1;
				d[i] = int.Parse(parts[2]);
			}
			int[] x = new int[t];
			for (int i = 0; i < t; i++)
				x[i] = int.Parse(Console.ReadLine()) - 1;

			List<int>[] outgoing = new List<int>[n];
			for (int i = 0; i < n; i++)
				outgoing[i] = new List<int>();
			int distgh = -1;
			for(int i = 0; i < m; i++)
			{
				outgoing[a[i]].Add(i);
				outgoing[b[i]].Add(i);
				if((a[i] == g && b[i] == h) || (a[i] == h && b[i] == g))
					distgh = d[i];
			}
			if(distgh == -1) throw new Exception();
			int[] starts = { s, g, h };
			int[,] dist = new int[starts.Length, n];
			for(int i = 0; i < starts.Length; i++)
			{
				bool[] done = new bool[n];
				PriorityQueue<State> Q = new PriorityQueue<State>();
				Q.Push(new State(starts[i], 0));
				while(Q.Count > 0)
				{
					State top = Q.Pop();
					if(done[top.i]) continue;
					done[top.i] = true;
					dist[i,top.i] = top.d;
					foreach(int j in outgoing[top.i])
						Q.Push(new State(a[j] == top.i ? b[j] : a[j], top.d + d[j]));
				}
			}

			bool first = true;
			Array.Sort(x);
			for (int i = 0; i < t; i++)
			{
				if (dist[0, x[i]] == dist[1, s] + distgh + dist[2, x[i]]
					|| dist[0, x[i]] == dist[1, x[i]] + distgh + dist[2, s])
				{
					if (!first) Console.Write(' ');
					first = false;
					Console.Write(x[i] + 1);
				}
			}
			Console.WriteLine();
		}
	}
}

class State : IComparable<State>
{
	public int i, d;

	public State(int i, int d)
	{
		this.i = i;
		this.d = d;
	}

	public int CompareTo(State other)
	{
		return d - other.d;
	}
}

/*** Prewritten, this is missing from C# :-( ***/
public class PriorityQueue<T>
{
	private T[] list;
	public int Count;
	public System.Collections.Generic.Comparer<T> Comparer;

	public PriorityQueue()
	{
		list = new T[1024];
		Count = 0;
		Comparer = System.Collections.Generic.Comparer<T>.Default;
	}

	public void Push(T value)
	{
		if (Count == list.Length)
		{
			T[] tmp = new T[list.Length * 2];
			System.Array.Copy(list, tmp, list.Length);
			list = tmp;
		}
		list[Count++] = value;
		int i = Count - 1;
		while (i > 0 && Comparer.Compare(list[i], list[parent(i)]) < 0)
		{
			T tmp = list[i];
			list[i] = list[parent(i)];
			list[parent(i)] = tmp;
			i = parent(i);
		}
	}

	public T Pop()
	{
		T ret = list[0];
		list[0] = list[--Count];
		int i = 0;
		while (true)
		{
			int left = (i * 2) + 1;
			if (left >= Count) break;
			int right = left + 1;
			int ind = left;
			if (right < Count && Comparer.Compare(list[left], list[right]) >
					0)
				ind = right;
			if (Comparer.Compare(list[i], list[ind]) >= 0)
			{
				T tmp = list[i];
				list[i] = list[ind];
				list[ind] = tmp;
				i = ind;
			}
			else break;
		}
		return ret;
	}

	private int parent(int i)
	{
		return (i - 1) / 2;
	}
}

