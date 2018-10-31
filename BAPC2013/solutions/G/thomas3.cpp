// Solution to Getting Through
// Author: Thomas Beuman

// Time complexity: O(n^2*log(n))
// Memory: O(n^2)

// @EXPECTED_RESULTS@: CORRECT

/*
Solution method: similar to Kruskal's algorithm for a minimum spanning tree

Largest circle that can get through (just) = smallest circle that cannot (just)

A circle cannot get through iff there is a path between the walls via the sensors,
such that the circle cannot fit between any pair of consecutive sensors/walls on the path.

Build a complete graph with all the sensors and the two walls,
where the edge lengths are the maximum radius a circle can have
in order to fit through the two sensors/walls represented by the two vertices.

Sort all the edges by length. Set all edges to "off".
Keep turning them on (from short to long) until the two walls belong to the same component.
The answer is the length of the last edge used.
*/


#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;


struct edge
{ int i, j;
  double len;
  edge(){}
  edge (int x, int y, double d)
  { i = x;
    j = y;
    len = d;
  }
};

bool operator< (edge E1, edge E2)
{ return E1.len < E2.len;
}


const int N = 1000;

int X[N], Y[N], R[N];

edge E[((N+2)*(N+1))/2];
int Parent[N+2], Generations[N+2];


double eucldis (int i, int j)
{ return sqrt((long long)(X[i]-X[j])*(X[i]-X[j]) + (long long)(Y[i]-Y[j])*(Y[i]-Y[j]));
}


int main()
{ int cases, casenr, w, n, m, i, j, wall1, wall2, k, a, b;
  
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
    E[0] = edge(wall1, wall2, w / 2.0);
    m = 1; // Number of edges
    for (i = 0; i < n; i++)
    { E[m++] = edge(i, wall1, max(0.0, (X[i] - R[i]) / 2.0));
      E[m++] = edge(i, wall2, max(0.0, (w - X[i] - R[i]) / 2.0));
      for (j = i+1; j < n; j++)
        E[m++] = edge(i, j, max(0.0, (eucldis(i, j) - R[i] - R[j]) / 2.0));
    }
    sort(E, E+m);

    // Initialize all vertices to loners
    for (i = 0; i < n+2; i++)
    { Parent[i] = i;
      Generations[i] = 0;
    }

    for (k = 0; Parent[wall1] != Parent[wall2] && k < m; k++)
    { 
      i = E[k].i;
      j = E[k].j;

      // Determine ancestors
      for (a = i; a != Parent[a]; a = Parent[a]);
      for (b = j; b != Parent[b]; b = Parent[b]);

      if (a == b) // i and j are already in the same component: ignore
        continue;

      // Make the "more senior" ancestor the parent of the other
      if (Generations[a] >= Generations[b])
      { Parent[b] = a;
        if (Generations[a] == Generations[b])
          Generations[a]++;
      }
      else
        Parent[a] = b;

      // Update the parents of the walls so that they link directly to their ancestors
      if (Parent[wall1] == a || Parent[wall1] == b)
        Parent[wall1] = Parent[a]; // (Note: Parent[a] == Parent[b])
      if (Parent[wall2] == a || Parent[wall2] == b)
        Parent[wall2] = Parent[a];
    }

    // Print length of last edge used
    printf("%lf\n", E[k-1].len);
  }
  return 0;
}

