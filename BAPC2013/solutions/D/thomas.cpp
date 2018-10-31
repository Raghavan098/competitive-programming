// Solution to Destination Unknown
// Author: Thomas Beuman

// Time complexity: O(n^2)
// Memory: O(n^2)

// @EXPECTED_RESULTS@: CORRECT

/*
Solution method: three times dijkstra

For each destination, check whether the shortest distance from s to that destination
equals the shortest distance to g + the length of the road between g and h
+ the shortest distance from h to the destination, or with g and h reversed
*/


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int N = 2001;
const int inf = 0x7fffffff; // "Infinity"

int T[N], Len[N][N];
bool Seen[N];

int DisS[N], DisG[N], DisH[N]; // Shortest distance from s, g, h


// Shortest distance from one vertex to all others
void dijkstra (int n, int start, int Dis[])
{ int i, j;
  for (i = 1; i <= n; i++)
  { Seen[i] = false;
    Dis[i] = inf;
  }
  Dis[start] = 0;

  while (true)
  { 
    // Look for closest unseen vertex
    i = -1;
    for (j = 1; j <= n; j++)
      if (!Seen[j] && Dis[j] < inf && (i == -1 || Dis[j] < Dis[i]))
        i = j;

    if (i == -1) // All reachable vertices processed: done!
      return;

    Seen[i] = true;

    // Update distances
    for (j = 1; j <= n; j++)
      if (Len[i][j] >= 0)
        Dis[j] = min(Dis[j], Dis[i] + Len[i][j]);
  }
}


int main()
{ int cases, casenr, n, m, t, s, g, h, i, a, b, d, x;
  bool first;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d %d %d\n%d %d %d\n", &n, &m, &t, &s, &g, &h);
    memset(Len, -1, sizeof(Len));
    for (i = 0; i < m; i++)
    { scanf("%d %d %d\n", &a, &b, &d);

      // Check testdata
      if (a == b)
      { fprintf(stderr, "Error in testcase %d: ", casenr);
        fprintf(stderr, "there is a road from vertex %d to itself!\n", a);
      }
      if (Len[a][b] >= 0)
      { fprintf(stderr, "Error in testcase %d: ", casenr);
        fprintf(stderr, "there is a second road between vertices %d and %d!\n", a, b);
      }

      Len[a][b] = Len[b][a] = d;
    }
    for (i = 0; i < t; i++)
      scanf("%d\n", &T[i]);
    sort(T, T+t);

    // Compute distances
    dijkstra(n, s, DisS);
    dijkstra(n, g, DisG);
    dijkstra(n, h, DisH);

    // Check testdata
    if (DisG[h] != Len[g][h])
    { fprintf(stderr, "Error in testcase %d: ", casenr);
      fprintf(stderr, "the road between g and h is not the shortest path!\n");
    }

    // Check destinations
    first = true;
    for (i = 0; i < t; i++)
    { x = T[i];
      if (DisS[x] == DisS[g] + Len[g][h] + DisH[x] || DisS[x] == DisS[h] + Len[h][g] + DisG[x])
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

