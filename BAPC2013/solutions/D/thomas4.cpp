// Solution to Destination Unknown
// Author: Thomas Beuman

// Time complexity: O(n*m)
// Memory: O(n^2)

// @EXPECTED_RESULTS@: CORRECT

/*
Solution method: Bellman-Ford

For each destination, check whether the shortest distance from s to that destination
equals the shortest distance to g + the length of the road between g and h
+ the shortest distance from h to the destination, or with g and h reversed

This solution uses the slower Bellman-Ford algorithm (three times)
*/


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int N = 2001, M = 100000;
const int inf = 0x3fffffff; // "Infinity"

int T[N], A[M], B[M], D[M];

int DisS[N], DisG[N], DisH[N]; // Shortest distance from s, g, h


// Bellman-Ford (shortest path from start to any other vertex)
void bellmanford (int n, int m, int start, int Dis[])
{ int i, j;
  for (i = 1; i <= n; i++)
    Dis[i] = inf;
  Dis[start] = 0;
  for (i = 0; i < n-1; i++)
    for (j = 0; j < m; j++)
	  Dis[B[j]] = min(Dis[B[j]], Dis[A[j]] + D[j]);
}


int main()
{ int cases, casenr, n, m, t, s, g, h, i, a, b, d, x;
  bool first;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d %d %d\n%d %d %d\n", &n, &m, &t, &s, &g, &h);
    for (i = 0; i < m; i++)
    { scanf("%d %d %d\n", &a, &b, &d);
      A[2*i] = B[2*i+1] = a;
      B[2*i] = A[2*i+1] = b;
      D[2*i] = D[2*i+1] = d;
    }
    for (i = 0; i < t; i++)
      scanf("%d\n", &T[i]);
    sort(T, T+t);

    // Compute distances
    bellmanford(n, 2*m, s, DisS);
    bellmanford(n, 2*m, g, DisG);
    bellmanford(n, 2*m, h, DisH);

    // Check destinations
    first = true;
    for (i = 0; i < t; i++)
    { x = T[i];
      if (DisS[x] == DisS[g] + DisG[h] + DisH[x] || DisS[x] == DisS[h] + DisH[g] + DisG[x])
      { if (!first)
          printf(" ");
        first = false;
        printf("%d", x);
      }
    }
    if (first)
      printf("No possible destinations!");
    printf("\n");
  }
  return 0;
}

