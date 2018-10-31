/*
 *  @EXPECTED_RESULTS@: CORRECT
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

typedef double TP;

struct point {
    TP x,y;
    
    point() {}
    
    point(TP nx, TP ny) : x(nx), y(ny) {}
    
    point conj() const {
        return point(x, -y);
    }
    
    point operator+(const point &p) const {
        return point(x + p.x, y + p.y);
    }
    
    point operator-(const point &p) const {
        return point(x - p.x, y - p.y);
    }
    
    point operator*(const TP c) const {
        return point(x * c, y * c);
    }
    
    point operator*(const point &p) const {
        return point((x * p.x) - (y * p.y), (x * p.y) + (y * p.x));
    }

    point operator/(const TP c) const {
        return point(x / c, y / c);
    }
    
    point operator/(const point &p) const {
        return (*this * p.conj()) / (p.x * p.x + p.y * p.y);
    }
    
    bool operator==(const point &p) const {
		return (abs(x - p.x) < 1e-6) && (abs(y - p.y) < 1e-6);
	}
    
    bool operator!=(const point &p) const {
		return (abs(x - p.x) > 1e-6) || (abs(y - p.y) > 1e-6);
	}
    
    double length() const {
        return hypot(x, y);
    }
    
    TP dot(const point &p) const {
        return (x * p.x) + (y * p.y);
    }
    
    TP cross(const point &p) const {
        return (x * p.y) - (p.x * y);
    }
};

struct line {
    TP a, b, c;
    
    line() {}
    
    line(TP na, TP nb, TP nc)
        : a(na), b(nb), c(nc) {}

    explicit line(const point &p) 
        : a(-p.y), b(p.x), c(0) {}

    line(const point &p, const point &q) 
        : a(q.y - p.y), b(p.x - q.x), c(a*p.x + b*p.y) {}
    
    line shift(const point &p) const {
        return line(a, b, c + (a * p.x) + (b * p.y));
    }
    
    point perp() const {
        return point(a,b);
    }
    
    point intersect(const line &m) const {
        double d = (m.a * b) - (a * m.b);
        if (abs(d) < 1e-6) ; // lines are parallel
        return point( (b*m.c - m.b*c)/d , (m.a*c - a*m.c)/d );
    }
    
    bool parallel(const line &m) const {
        return abs((m.a * b) - (a * m.b)) < 1e-6;
    }
};

void bisect(line a, line b, line r[2]) {
    point c = a.intersect(b);
    point d(a.a, a.b);
    point e(b.a, b.b);
    d = d/d.length();
    e = e/e.length();
    r[0] = line(d + e).shift(c);
    r[1] = line(d - e).shift(c);
}

struct segment {
    point a;
    point b;
    
    segment(const point &na, const point &nb)
        : a(na), b(nb) {}

    point project(const point &p) const {
        double l = (p-a).dot(b-a)/(b-a).dot(b-a);
        if (l<0) l=0;
        if (l>1) l=1;
        return a+(b-a)*l;
    }

    double dist(const point &p) const {
        return (p-project(p)).length();
    }
};

double area(vector<point> &points)
{
	double a = 0;
	points.push_back(points[0]);
	for (size_t i = 1; i < points.size(); i++)
	{
		a += points[i-1].cross(points[i]);
	}
	points.pop_back();
	return abs(a/2);
}

void dostep()
{
	int n;
	cin >> n;
	
	vector<point> points(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> points[i].x >> points[i].y;
	}
	
	double full_area = area(points);
	
	// Determine camera position
	point camera = points[0] + ((points[1] - points[0]) / 2);
	
	// Determine view-lines
	line ab(points[0], points[1]);
	line perp(camera, camera + ab.perp());
	line bisects[2];
	bisect(ab, perp, bisects);
	
	// Determine visible polygon
	vector<point> pts;
	pts.push_back(camera);
	bool copy = false;
	points.push_back(points[0]);
	for (size_t i = 2; i < points.size(); i++)
	{
		segment s(points[i-1], points[i]);
		line l(points[i-1], points[i]);
		
		for (int j = 0; j < 2; j++)
		{
			if (!l.parallel(bisects[j]))
			{
				point p = l.intersect(bisects[j]);
				if ((s.dist(p) < 1e-6) && (p != points[i]))
				{
					// Intersection
					pts.push_back(p);
					copy = !copy;
				}
			}
		}
		
		if (copy)
		{
			pts.push_back(points[i]);
		}
	}
	
	double view_area = area(pts);
	
	printf("%.6f\n", view_area / full_area);
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	return 0;
}
