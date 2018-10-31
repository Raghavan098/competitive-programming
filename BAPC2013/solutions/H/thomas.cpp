// Solution to Hidden Camera
// Author: Thomas Beuman

// Time complexity: O(n)
// Memory: O(n)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: binary search


#include <cstdio>
#include <cmath>
#include <utility>
using namespace std;


double X[1001], Y[1001];
double XV[1001], YV[1001]; // The vertices describing the camera's view

double pi = acos(-1);
double base_angle; // Angle made by the base wall with respect to the (positive) x-axis


// Returns the area of a polygon
double area (int n, double x[], double y[])
{ double A = 0;
  int i, j;
  for (i = 0; i < n; i++)
  { j = (i+1) % n;
    A += x[i]*y[j] - y[i]*x[j];
  }
  return A/2;
}

// Computes angle with respect to the base wall
double angle (double x, double y)
{ double a = atan2(y, x) - base_angle;
  return a < 0 ? a + 2*pi : a;
}

// Finds the point on the edge between vertices i and j
// for which the angle with the base wall equals target_angle
pair<double,double> binary_search (int i, int j, double target_angle)
{ double x0 = X[i], y0 = Y[i], dx = X[j]-X[i], dy = Y[j]-Y[i], lb = 0, ub = 1, a, x = x0, y = y0;
  while ((ub-lb)*fabs(dx) > 1e-8 || (ub-lb)*fabs(dy) > 1e-8)
  { a = (lb+ub)/2;
    x = x0 + a*dx;
    y = y0 + a*dy;
    if (angle(x, y) < target_angle)
      lb = a;
    else
      ub = a;
  }
  return make_pair(x, y);
}


int main()
{ int cases, casenr, n, i, m, j;
  double xc, yc;
  pair<double,double> V;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
      scanf("%lf %lf\n", &X[i], &Y[i]);

    // Location of camera
    xc = (X[0]+X[1])/2;
    yc = (Y[0]+Y[1])/2;
    // Translate the polygon so that the camera is at (0,0)
    for (i = 0; i < n; i++)
    { X[i] -= xc;
      Y[i] -= yc;
    }
    X[n] = X[0];
    Y[n] = Y[0];
    base_angle = atan2(Y[1], X[1]);

    XV[0] = 0;
    YV[0] = 0;
    m = 1;

    for (i = 2; i < n && angle(X[i], Y[i]) < pi/4; i++); // Find first vertex in view of camera
    for (j = n-1; j > 1 && angle(X[j], Y[j]) > 3*pi/4; j--); // Find last vertex in view

    // Find the point on the edge i-1 -> i that makes a 45 degree angle with the base wall
    V = binary_search(i-1, i, pi/4);
    XV[m] = V.first;
    YV[m] = V.second;
    m++;

    // Add all vertices that are in the camera's view
    for (; i <= j; i++)
    { XV[m] = X[i];
      YV[m] = Y[i];
      m++;
    }

    // Find the point on the edge j -> j+1 that makes a 135 degree angle with the base wall
    V = binary_search(j, j+1, 3*pi/4);
    XV[m] = V.first;
    YV[m] = V.second;
    m++;

    printf("%lf\n", area(m, XV, YV) / area(n, X, Y));
  }
  return 0;
}

