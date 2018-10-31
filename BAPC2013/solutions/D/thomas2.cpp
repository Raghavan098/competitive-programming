// Solution to Destination Unknown
// Author: Thomas Beuman

// Time complexity: O(n*m)
// Memory: O(n^2)

// @EXPECTED_RESULTS@: CORRECT

/*
Solution method: Bellman-Ford

Double all the distances, decrease the distance of the road between g and h by one
The road between g and h is part of a shortest path from s to x iff the distance to x is odd

This solution uses the slower Bellman-Ford algorithm (once)
*/


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int N = 2001, M = 100000;
const int inf = 0x3ffffffe; // "Infinity" (even)

int T[N], A[M], B[M], D[M];
int Dis[N];


// Bellman-Ford (shortest path from start to any other vertex)
void bellmanford (int n, int m, int start)
{ int i, j;
  for (i = 1; i <= n; i++)
    Dis[i] = inf;
  Dis[start] = 0;
  for (i = 0; i < n-1; i++)
    for (j = 0; j < m; j++)
      Dis[B[j]] = min(Dis[B[j]], Dis[A[j]] + D[j]);
}


int main()
{ int cases, casenr, n, m, t, s, g, h, i, a, b, d;
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
      // Double all distances, subtract one from road between g and h
      D[2*i] = D[2*i+1] = (((a==g && b==h) || (a==h && b==g)) ? 2*d-1 : 2*d);
    }
    for (i = 0; i < t; i++)
      scanf("%d\n", &T[i]);
    sort(T, T+t);

    // Compute distances
    bellmanford(n, 2*m, s);

    // Check destinations
    first = true;
    for (i = 0; i < t; i++)
    { if (Dis[T[i]] % 2 == 1) // Check if odd
      { if (!first)
          printf(" ");
        first = false;
        printf("%d", T[i]);
      }
    }
    if (first)
      printf("No possible destinations!");
    printf("\n");
  }
  return 0;
}

