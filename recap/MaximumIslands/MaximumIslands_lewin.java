import java.util.Arrays;
import java.util.Scanner;

public class MaximumIslands_lewin {
  public static int[] dx = {0,1,0,-1}, dy = {1,0,-1,0};
  public static char[][] grid;
  public static int n, m;
  public static void main (String[] args) {
    Scanner in = new Scanner(System.in);
    n = in.nextInt();
    m = in.nextInt();
    grid = new char[n][m];
    for (int i = 0; i < n; i++) {
      grid[i] = in.next().toCharArray();
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 'L') {
          ans++;
          dfs(i,j);
        }
      }
    }
    
    init(n*m+2, 2*5*n*m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] != 'C') continue;
        ans++;
        if ((i+j) % 2 == 0) {
          add_edge(N-1, i*m+j, 1);
          for (int k = 0; k < 4; k++) {
            int nx = i+dx[k], ny = j+dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 'C') continue;
            add_edge(i*m+j, nx*m+ny, 1);
          }
        } else {
          add_edge(i*m+j, N-2, 1);
        }
      }
    }
    System.out.println(ans - dinic(N-1, N-2));
    System.exit(0);
  }
  
  public static void dfs(int x, int y) {
    grid[x][y] = 'W';
    for (int i = 0; i < 4; i++) {
      int nx = x+dx[i], ny = y+dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (grid[nx][ny] == 'L') dfs(nx,ny);
      grid[nx][ny] = 'W';
    }
  }
  
  public static int N;
  public static int INF = 1 << 29;
  public static int[] eadj, eprev, elast;
  public static int eidx;
  private static int[] flow, capa, now;

  public static void init(int _N, int M) {
    N = _N;
    eadj = new int[M];
    eprev = new int[M];
    elast = new int[N];
    flow = new int[M];
    capa = new int[M];
    now = new int[N];
    level = new int[N];
    eidx = 0;
    Arrays.fill(elast, -1);
  }

  private static void add_edge(int a, int b, int c) {
    eadj[eidx] = b; flow[eidx] = 0; capa[eidx] = c; eprev[eidx] = elast[a]; elast[a] = eidx++;
    eadj[eidx] = a; flow[eidx] = c; capa[eidx] = c; eprev[eidx] = elast[b]; elast[b] = eidx++;
  }

  private static int dinic(int source, int sink) {
    int res, flow = 0;
    while (bfs(source, sink)) { // see if there is an augmenting path
      System.arraycopy(elast, 0, now, 0, N);
      while ((res = dfs(source, INF, sink)) > 0)
        // push all possible flow through
        flow += res;
    }
    return flow;
  }

  private static int[] level;

  private static boolean bfs(int source, int sink) {
    Arrays.fill(level, -1);
    int front = 0, back = 0;
    int[] queue = new int[N];
    level[source] = 0;
    queue[back++] = source;
    while (front < back && level[sink] == -1) {
      int node = queue[front++];
      for (int e = elast[node]; e != -1; e = eprev[e]) {
        int to = eadj[e];
        if (level[to] == -1 && flow[e] < capa[e]) {
          level[to] = level[node] + 1;
          queue[back++] = to;
        }
      }
    }

    return level[sink] != -1;
  }

  private static int dfs(int cur, int curflow, int goal) {
    if (cur == goal)
      return curflow;

    for (int e = now[cur]; e != -1; now[cur] = e = eprev[e]) {
      if (level[eadj[e]] > level[cur] && flow[e] < capa[e]) {
        int res = dfs(eadj[e], Math.min(curflow, capa[e] - flow[e]), goal);
        if (res > 0) {
          flow[e] += res;
          flow[e ^ 1] -= res;
          return res;
        }
      }
    }
    return 0;
  }
}
