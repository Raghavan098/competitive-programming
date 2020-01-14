const double eps=1e-9;
const double PI= acos(-1);
inline int sgn(double x)
{
    if (x>eps) return 1;
    if (x<-eps) return -1;
    return 0;
}
inline double sqr(double x)
{
    return x*x;
}
struct Point{
    double x,y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point(pair<double,double> p) : x(p.first), y(p.second) {}
    bool operator == (const Point &p) const{
        return sgn(x-p.x)==0 && sgn(y - p.y) == 0;
    }
    bool operator != (const Point &p) const{
        return sgn(x-p.x)!=0 || sgn(y - p.y) != 0;
    }
    inline double length() const{
        return sqrt(sqr(x) + sqr(y));
    }
    inline double angle() const{
        return atan2(y, x);
    }
};
typedef Point Vector;
Vector operator + (Vector a, Vector b)
{
    return Vector(a.x + b.x, a.y + b.y);
}
Vector operator - (Vector a, Vector b)
{
    return Vector(a.x - b.x, a.y - b.y);
}
Vector operator * (Vector v, double mul)
{
    return Vector(v.x * mul, v.y * mul);
}
Vector operator / (Vector v, double div)
{
    return Vector(v.x / div, v.y / div);
}
inline double dist (Point a, Point b)
{
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
Vector rot(Vector v, double rad)
{
    return Vector(v.x * cos(rad) - v.y * sin(rad),
                  v.x * sin(rad) + v.y * cos(rad));
}
Vector unit(Vector v)
{
    return v/v.length();
}
inline double cross(Vector a, Vector b)
{
    return a.x * b.y - a.y * b.x;
}
inline double dot(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y;
}
inline double angle(Vector a, Vector b)
{
    return acos(dot(a,b) / a.length() / b.length());
}

struct Segment{
    Point s,e;
    Segment() {}
    Segment(Point s, Point e) : s(s), e(e) {}
    inline double length() const{
        return dist(s, e);
    }
    inline double y(double x) const{
        return s.y + (e.y - s.y)*(x - s.x) / (e.x - s.x);
    }
};

struct Circle{
    Point o;
    double r;
    Circle() {}
    Circle(Point o, double r) : o(o), r(r) {}
    Circle(Point a, Point b) : o((a+b) / 2), r(dist(a,b) / 2) {}
};

int circle_tangent(Point p, Circle cir, Vector *v)
{
    Vector u = cir.o - p;
    double d = dist(cir.o, p);
    if (sgn(d - cir.r) < 0) return 0;
    else if (sgn(d - cir.r) == 0)
    {
        v[0]=rot(u, PI / 2);
        return -1;
    }
    else
    {
        double ang = asin(cir.r/d);
        v[0] = rot(u, -ang);
        v[1] = rot(u, ang);
        return 2;
    }
}
Point project_on_line(Point p, Segment l)
{
    Vector v = l.e - l.s;
    return l.s + v * (dot(v, p - l.s) / dot(v, v));
}
double dist_to_line(Point p, Segment l)
{
    Vector u = p - l.s, v = p - l.e;
    return fabs(cross(u,v)) / l.length();
}
int line_intersect_circle(Segment l, Circle cir, Point & res)
{
    Point p=project_on_line(cir.o, l);
    double d = dist_to_line(cir.o ,l);
    if (sgn(d-cir.r) > 0) return 0;
    else if (sgn(d - cir.r) ==0)
    {
        res=p;
        return 1;
    }
    assert(false);
}
