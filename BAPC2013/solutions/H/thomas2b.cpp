// Solution to Hidden Camera
// Author: Thomas Beuman

// Time complexity: O(n)
// Memory: O(n)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: geometric calculation (higher precision)


#include <cstdio>
using namespace std;


typedef long double dbl;


int X[1000], Y[1000];
dbl XV[1001], YV[1001]; // The vertices describing the camera's view


// Returns whether line ab and line cd intersect (i.e. are not parallel)
// When so, the intersection point is (x,y)
bool intersection (int xa, int ya, int xb, int yb,
                   int xc, int yc, int xd, int yd, dbl& x, dbl& y)
{ int d = (xa-xb)*(yc-yd) - (xc-xd)*(ya-yb);
  if (d == 0)
    return false;
  x = -((long long)(xa-xb)*(xc*yd-xd*yc) - (long long)(xc-xd)*(xa*yb-xb*ya)) / (dbl)(d);
  y =  ((long long)(ya-yb)*(yc*xd-yd*xc) - (long long)(yc-yd)*(ya*xb-yb*xa)) / (dbl)(d);
  return true;
}

// Returns the area of a polygon
template <class number>
dbl area (int n, number x[], number y[])
{ dbl A = 0;
  int i, j;
  for (i = 0; i < n; i++)
  { j = (i+1) % n;
    A += x[i]*y[j] - y[i]*x[j];
  }
  return A/2;
}

// Returns whether (x,y) is (strictly) to the left of the (extended) line from (x1,y1) to (x2,y2)
bool totheleft (int x, int y, int x1, int y1, int x2, int y2)
{ return (x-x1)*(y-y2) > (x-x2)*(y-y1);
}


int main()
{ int cases, casenr, n, i, m, j, xc, yc, x45, y45, x135, y135;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
      scanf("%d %d\n", &X[i], &Y[i]);

    // Coordinates of the camera (doubled, hence integer)
    xc = X[0]+X[1];
    yc = Y[0]+Y[1];
    // Double all the coordinates
    for (i = 0; i < n; i++)
    { X[i] *= 2;
      Y[i] *= 2;
    }
    // (x45,y45) is a point on the line marking the right limit of the camera's view
    // (the line (xc,yc) -> (x45,y45) makes a 45 degree angle with (xc,yc) -> (X[1], Y[1]))
    x45 = X[1] - Y[1] + yc;
    y45 = Y[1] + X[1] - xc;
    // (x135,y135) is on the left line
    x135 = X[0] + Y[0] - yc;
    y135 = Y[0] - X[0] + xc;

    XV[0] = xc;
    YV[0] = yc;
    m = 1;

    for (i = 1; i < n; i++)
    { j = (i+1) % n; // The next vertex

      // Check if the right border crosses the edge i->j
      if (!totheleft(X[i], Y[i], xc, yc, x45, y45) && totheleft(X[j], Y[j], xc, yc, x45, y45))
      { if (!intersection(xc, yc, x45, y45, X[i], Y[i], X[j], Y[j], XV[m], YV[m]))
          fprintf(stderr, "Something's wrong!\n");
        m++;
      }

      // Check if vertex i is in the camera's view
      if (totheleft(X[i], Y[i], xc, yc, x45, y45) && !totheleft(X[i], Y[i], xc, yc, x135, y135))
      { XV[m] = X[i];
        YV[m] = Y[i];
        m++;
      }

      // Check if the left border crosses the edge i->j
      if (!totheleft(X[i], Y[i], xc, yc, x135, y135) && totheleft(X[j], Y[j], xc, yc, x135, y135))
      { if (!intersection(xc, yc, x135, y135, X[i], Y[i], X[j], Y[j], XV[m], YV[m]))
          fprintf(stderr, "Something's wrong!\n");
        m++;
      }
    }

    printf("%.10Lf\n", area(m, XV, YV) / area(n, X, Y));
  }
  return 0;
}

