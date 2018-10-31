// Solution to Getting Through
// Author: Thomas Beuman

// Time complexity: O(n^2*log(n))
// Memory: O(n^2)

// @EXPECTED_RESULTS@: CORRECT

/*
Solution method: binary search (over all edge lengths)

Largest circle that can get through (just) = smallest circle that cannot (just)

A circle cannot get through iff there is a path between the walls via the sensors,
such that the circle cannot fit between any pair of consecutive sensors/walls on the path.

Build a complete graph with all the sensors and the two walls,
where the edge lengths are the maximum radius a circle can have
in order to fit through the two sensors/walls represented by the two vertices.

Do a binary search over all edge lengths. For each, do a breadth-first search to see
whether there is a path from one wall to the other, using only edges of at most that length.
The answer is the smallest edge length for which there is a path.
*/


#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;


const int N = 1000;

int X[N], Y[N], R[N];
double Len[N+2][N+2]; // Maximum radius that can fit between sensors i and j
double All[((N+2)*(N+1))/2]; // List of all radii

int BFSqueue[N+2];
bool OnQueue[N+2];


double eucldis (int i, int j)
{ return sqrt((long long)(X[i]-X[j])*(X[i]-X[j]) + (long long)(Y[i]-Y[j])*(Y[i]-Y[j]));
}


int main()
{ int cases, casenr, w, n, m, i, j, wall1, wall2, lb, ub, mid, cur, last;
  double maxlen;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d\n%d\n", &w, &n);
    for (i = 0; i < n; i++)
      scanf("%d %d %d\n", &X[i], &Y[i], &R[i]);

    // Add walls as vertices
    wall1 = n;
    wall2 = n+1;

    // Compute all edge lengths
    All[0] = Len[wall1][wall2] = Len[wall2][wall1] = w / 2.0;
    m = 1; // Number of edges
    for (i = 0; i < n; i++)
    { All[m++] = Len[i][wall1] = Len[wall1][i] = max(0.0, (X[i] - R[i]) / 2.0);
      All[m++] = Len[i][wall2] = Len[wall2][i] = max(0.0, (w - X[i] - R[i]) / 2.0);
      for (j = i+1; j < n; j++)
        All[m++] = Len[i][j] = Len[j][i] = max(0.0, (eucldis(i, j) - R[i] - R[j]) / 2.0);
    }
    sort(All, All+m);

    /*** Binary search ***/
    lb = -1; // Lower bound (impossible)
    ub = m-1; // Upper bound (possible)
    while (lb < ub-1)
    { mid = (lb + ub) / 2;
      maxlen = All[mid]; // Set maximum length

      // Breadth-first search
      memset(OnQueue, false, sizeof(OnQueue));
      BFSqueue[0] = wall1;
      OnQueue[wall1] = true;
      last = 1;
      for (cur = 0; cur < last && !OnQueue[wall2]; cur++)
      { i = BFSqueue[cur];
        for (j = 0; j < n+2; j++)
          if (!OnQueue[j] && Len[i][j] <= maxlen)
          { BFSqueue[last++] = j;
            OnQueue[j] = true;
          }
      }

      // Update bounds
      if (OnQueue[wall2]) // Right wall reachable
        ub = mid;
      else
        lb = mid;
    }

    printf("%lf\n", All[ub]);
  }
  return 0;
}

