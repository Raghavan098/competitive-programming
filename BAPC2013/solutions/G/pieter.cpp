// Solution to Getting Through
// Author: Pieter Bootsma

// Time complexity: O(log(w) * n^2)
// Memory: O(n^2)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: binary search over diameter; precalculate gaps between sensors

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

struct unionfind
{
	unionfind * p;
	int rank;
	
	void makeset()
	{ 
		p = this;
		rank = 0;
	}
	
	unionfind *findset()
	{
		if (p->p != p)
		{
			p = p->findset();
		}
		return p;
	}
	
	void combine(unionfind &q)
	{
		unionfind *a = findset();
		unionfind *b = q.findset();
		
		if (a->rank < b->rank)
		{
			a->p = b;
		}
		else
		{
			b->p = a;
			if (a->rank == b->rank) a->rank++;
		}
	}
};


struct Sensor
{
	int x;
	int y;
	int r;
	unionfind uf;
};

int nsensors;
Sensor sensors[1005];
double gap[1005][1005];

bool test(double r, double w)
{
	unionfind left, right;
	left.makeset();
	right.makeset();
	
	for (int i = 0; i < nsensors; i++)
	{
		sensors[i].uf.makeset();
		
		if ((sensors[i].x - sensors[i].r - r) <= 0)
			sensors[i].uf.combine(left);
		if ((sensors[i].x + sensors[i].r + r) >= w)
			sensors[i].uf.combine(right);
	}
	
	for (int a = 0; a < nsensors; a++)
	{
		for (int b = 0; b < a; b++)
		{
			if (gap[a][b] <= r)
			{
				sensors[a].uf.combine(sensors[b].uf);
			}
		}
	}
	
	return (left.findset() != right.findset());
}

void dostep()
{
	int w;
	cin >> w;
	
	cin >> nsensors;
	for (int i = 0; i < nsensors; i++)
	{
		cin >> sensors[i].x >> sensors[i].y >> sensors[i].r;
	}
	
	for (int a = 0; a < nsensors; a++)
	{
		gap[a][a] = 0;
		for (int b = 0; b < a; b++)
		{
			int xd = sensors[a].x - sensors[b].x;
			int yd = sensors[a].y - sensors[b].y;
			double d = sensors[a].r + sensors[b].r;
			gap[a][b] = gap[b][a] = hypot(xd, yd) - d;
		}
	}
	
	double a = 0, b = w;
	while (a < (b - 1e-6))
	{
		double c = (a + b) / 2;
		(test(c, w) ? a : b) = c;
	}
	
	printf("%.6f\n", a/2);
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	return 0;
}
