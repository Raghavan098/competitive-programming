// Solution to Jailbreak
// Author: Thomas Beuman

// Time complexity: O(h*w)
// Memory: O(h*w)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: breadth-first search
//   Determine shortest distance to all points from outside, person 1 and person 2 respectively
//   Look for point that minimizes the sum of all three


#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
#define mpii make_pair


const int N = 102;
char Map[N][N];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int Dis0[N][N], Dis1[N][N], Dis2[N][N];
queue<pii> BFS[2];


void shortestdis (int sx, int sy, int h, int w, int D[][N])
{ int d, t, x, y, x2, y2, i;
  pii p;
  memset(D, -1, N*N*sizeof(int));
  BFS[0] = queue<pii>();
  BFS[1] = queue<pii>();
  BFS[0].push(mpii(sx,sy));
  D[sy][sx] = d = 0;
  t = 0;
  while (!BFS[0].empty() || !BFS[1].empty())
  { if (BFS[t].empty())
    { d++;
      t = 1-t;
    }
    p = BFS[t].front();
    BFS[t].pop();
    x = p.first;
    y = p.second;
    for (i = 0; i < 4; i++)
    { x2 = x + dx[i];
      y2 = y + dy[i];
      if (x2 >= 0 && x2 < w && y2 >= 0 && y2 < h && Map[y2][x2] != '*' && D[y2][x2] == -1)
      { D[y2][x2] = d;
        BFS[Map[y2][x2] == '#' ? 1-t : t].push(mpii(x2,y2));
      }
    }
  }
}


int main()
{ int cases, casenr, h, w, x, y, p1x, p1y, p2x, p2y, dis;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d %d\n", &h, &w);
    for (y = 1; y <= h; y++)
      scanf("%s\n", Map[y]+1);
    for (x = 0; x <= w+1; x++)
      Map[0][x] = Map[h+1][x] = '.';
    for (y = 0; y <= h+1; y++)
      Map[y][0] = Map[y][w+1] = '.';

    p1x = p1y = p2x = p2y = 0;
    for (x = 1; x <= w; x++)
      for (y = 1; y <= h; y++)
        if (Map[y][x] == '$')
        { if (p1x == 0)
          { p1x = x;
            p1y = y;
          }
          else
          { p2x = x;
            p2y = y;
          }
        }
    shortestdis(0, 0, h+2, w+2, Dis0);
    shortestdis(p1x, p1y, h+2, w+2, Dis1);
    shortestdis(p2x, p2y, h+2, w+2, Dis2);
    dis = Dis0[0][0] + Dis1[0][0] + Dis2[0][0];
    /*for (y = 1; y < h+1; y++)
    { for (x = 1; x < w+1; x++)
        if (Dis0[y][x] >= 0)
          printf("  % d% d% d  ", Dis0[y][x], Dis1[y][x], Dis2[y][x]);
        else
          printf("          ");
      printf("\n");
    }//*/
    for (x = 1; x <= w; x++)
      for (y = 1; y <= h; y++)
        if (Dis0[y][x] >= 0)
          dis = min(dis, (Map[y][x] == '#' ? 1 : 0) + Dis0[y][x] + Dis1[y][x] + Dis2[y][x]);
    printf("%d\n", dis);
  }
  return 0;
}

