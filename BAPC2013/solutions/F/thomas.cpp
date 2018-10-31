// Solution to Flying Safely
// Author: Thomas Beuman

// Time complexity: O(n^2)
// Memory: O(n^2)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: breadth-first search
// (Effectively checks that the graph is connected)


#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;


const int N = 1000, M = 10000;

bool Connected[N][N];
bool Reachable[N];
queue<int> BFSqueue;


int main()
{ int cases, casenr, n, m, i, a, b, t, j;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d %d\n", &n, &m);
    memset(Connected, false, sizeof(Connected));
    for (i = 0; i < m; i++)
    { scanf("%d %d\n", &a, &b);
      Connected[a-1][b-1] = Connected[b-1][a-1] = true;
    }

    // Look for all cities that can be reached from city 1
    t = 0;
    memset(Reachable, false, sizeof(Reachable));
    BFSqueue.push(0);
    Reachable[0] = true;
    while (!BFSqueue.empty())
    { i = BFSqueue.front();
      BFSqueue.pop();
      for (j = 0; j < n; j++)
        if (Connected[i][j] && !Reachable[j])
        { Reachable[j] = true;
          t++; // Add new pilot
          BFSqueue.push(j);
        }
    }
    
    // Print result
    printf("%d\n", t);
  }
  return 0;
}

