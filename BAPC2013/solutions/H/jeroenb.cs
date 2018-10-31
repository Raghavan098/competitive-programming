/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;

public class jeroenb
{
	public static void Main(string[] args)
	{
		System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;

		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0)
		{
			int n = int.Parse(Console.ReadLine());
			Point[] points = new Point[n];
			for(int i = 0; i < n; i++)
			{
				string[] parts = Console.ReadLine().Split();
				points[i] = new Point(int.Parse(parts[0]), int.Parse(parts[1]));
			}
			Point camera = new Point((points[0].X + points[1].X) / 2, (points[0].Y + points[1].Y) / 2);
			double area = PolygonArea(points);
			double unused = 0;

			// Unused area in counterclockwise direction
			for(int i = 2; i <= n; i++)
			{
				if(MoreThan45Degree(camera, points[1], points[i%n]))
				{
					// 45 degrees angle is somewhere on this segment
					// binary search for the exact spot
					double low = 0;
					double up = 1;
					double dx = points[i%n].X - points[i-1].X;
					double dy = points[i%n].Y - points[i-1].Y;
					Point p = null;
					for(int j = 0; j < 50; j++)
					{
						double act = (low + up) / 2;
						p = new Point(points[i-1].X + act * dx, points[i-1].Y + act * dy);
						if(MoreThan45Degree(camera, points[1], p))
							up = act;
						else
							low = act;
					}
					unused += ((points[i-1] - camera) ^ (p - camera)) / 2;
					break;
				}
				unused += ((points[i-1] - camera) ^ (points[i%n] - camera)) / 2;
			}

			// Unused area in clockwise direction
			for(int i = n - 1; i >= 1; i--)
			{
				if(MoreThan45Degree(camera, points[i], points[0]))
				{
					double low = 0;
					double up = 1;
					double dx = points[i].X - points[(i+1)%n].X;
					double dy = points[i].Y - points[(i+1)%n].Y;
					Point p = null;
					for(int j = 0; j < 50; j++)
					{
						double act = (low + up) / 2;
						p = new Point(points[(i+1)%n].X + act * dx, points[(i+1)%n].Y + act * dy);
						if(MoreThan45Degree(camera, p, points[0]))
							up = act;
						else
							low = act;
					}
					unused += ((p - camera) ^ (points[(i+1)%n] - camera)) / 2;
					break;
				}
				unused += ((points[i] - camera) ^ (points[(i+1)%n] - camera)) / 2;
			}
			
			Console.WriteLine(1 - unused / area);
		}
	}

	private static bool MoreThan45Degree(Point A, Point B, Point C)
	{
		// A ^ B = |A||B|Sin(Theta)
		// A * B = |A||B|Cos(Theta)
		// (A ^ B) / (A * B) = Tan(Theta)
		double angle = Math.Atan2(((B - A) ^ (C - A)), ((B - A) * (C - A)));
		return angle >= Math.PI / 4;
	}

	public static double PolygonArea(Point[] polygon)
	{
		double area = 0;
		for (int i = 1; i < polygon.Length - 1; i++)
			area += (polygon[i] - polygon[0]) ^ (polygon[i + 1] - polygon[0]);
		return area / 2;
	}

	public class Point
	{
		public double X, Y;

		public Point(double x, double y)
		{
			X = x; Y = y;
		}

		public double Length
		{
			get
			{
				return Math.Sqrt(this * this);
			}
		}

		public static Point operator -(Point A, Point B)
		{
			return new Point(A.X - B.X, A.Y - B.Y);
		}

		/* Dot product of A * B = |A||B|Cos(Theta) */
		public static double operator *(Point A, Point B)
		{
			return A.X * B.X + A.Y * B.Y;
		}

		/* Cross product of A ^ B = |A||B|Sin(Theta) */
		public static double operator ^(Point A, Point B)
		{
			return A.X * B.Y - A.Y * B.X;
		}

		public override string ToString()
		{
			return X + "," + Y;
		}
	}
}

