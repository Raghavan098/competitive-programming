// Solution to Getting Through
// Author: Thomas Beuman

// Time complexity: O(n^2*log(n))
// Memory: O(n^2)

// @EXPECTED_RESULTS@: CORRECT

/*
Solution method: similar to Prim's algorithm for a minimum spanning tree (with priority queue)

Largest circle that can get through (just) = smallest circle that cannot (just)

A circle cannot get through iff there is a path between the walls via the sensors,
such that the circle cannot fit between any pair of consecutive sensors/walls on the path.

Build a complete graph with all the sensors and the two walls,
where the edge lengths are the maximum radius a circle can have
in order to fit through the two sensors/walls represented by the two vertices.

Starting from a connected subgraph containing only the left wall,
keep adding the vertex that requires the shortest edge to be connected.
Repeat until the right wall is added, the longest used edge is the answer.
*/


#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;


struct vertex
{ int i;
  double dis; // Distance to subgraph
  vertex(){}
  vertex (int x, double d)
  { i = x;
    dis = d;
  }
};

bool operator< (vertex V1, vertex V2)
{ return V1.dis > V2.dis; // Vertices further away have a lower priority
}


const int N = 1000;

int X[N], Y[N], R[N];
double Len[N+2][N+2]; // Maximum radius that can fit between sensors i and j
bool Seen[N+2];
priority_queue<vertex> pq;


double eucldis (int i, int j)
{ return sqrt((long long)(X[i]-X[j])*(X[i]-X[j]) + (long long)(Y[i]-Y[j])*(Y[i]-Y[j]));
}


int main()
{ int cases, casenr, w, n, i, j, wall1, wall2;
  double maxdis;
  vertex V;
  
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
    Len[wall1][wall2] = Len[wall2][wall1] = w / 2.0;
    for (i = 0; i < n; i++)
    { Len[i][wall1] = Len[wall1][i] = max(0.0, (X[i] - R[i]) / 2.0);
      Len[i][wall2] = Len[wall2][i] = max(0.0, (w - X[i] - R[i]) / 2.0);
      for (j = i+1; j < n; j++)
        Len[i][j] = Len[j][i] = max(0.0, (eucldis(i, j) - R[i] - R[j]) / 2.0);
    }

    // Initialize subgraph
    memset(Seen, false, sizeof(Seen));
    Seen[wall1] = true;
    pq = priority_queue<vertex>();
    for (i = 0; i < n+2; i++)
      if (i != wall1)
        pq.push(vertex(i, Len[wall1][i]));
    maxdis = 0;

    while (true)
    { 
      // Extract shortest edge
      V = pq.top();
      pq.pop();
      i = V.i;

      if (Seen[i]) // Vertex i is already added: ignore
        continue;
      maxdis = max(maxdis, V.dis);
      if (i == wall2) // Right wall added: done
        break;
      Seen[i] = true;

      // Add vertices to priority queue with new optional distance
      for (j = 0; j < n+2; j++)
        if (!Seen[j])
          pq.push(vertex(j, Len[i][j]));
    }

    printf("%lf\n", maxdis);
  }
  return 0;
}

