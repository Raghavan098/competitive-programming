import java.util.*;
public class BuggyRobot {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int r = scan.nextInt();
		int c = scan.nextInt();
		char[][] grid = new char[r][c];
		for(int i = 0; i < r; i++) {
			String s = scan.next();
			for(int j = 0; j < c; j++) {
				grid[i][j] = s.charAt(j);
			}
		}
		String ops = scan.next();
		int[][][] dp = new int[r][c][ops.length()+1];
		PriorityQueue<Vertex> q = new PriorityQueue<Vertex>();
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				Arrays.fill(dp[i][j], 1 << 25);
				if(grid[i][j] == 'R') {
					dp[i][j][0] = 0;
					q.add(new Vertex(i, j, 0, 0));
				}
			}
		}
		int ret = Integer.MAX_VALUE;
		int[] dx = new int[]{-1,1,0,0};
		int[] dy = new int[]{0,0,-1,1};
		while(!q.isEmpty()) {
			Vertex curr = q.poll();
			if(grid[curr.i][curr.j] == 'E') {
				ret = curr.w;
				break;
			}
			if(dp[curr.i][curr.j][curr.k] != curr.w) continue;
			for(int k = 0; k < dx.length; k++) {
				int nx = curr.i + dx[k];
				int ny = curr.j + dy[k];
				if(nx < 0 || nx >= r || ny < 0 || ny >= c || grid[nx][ny] == '#') {
					nx = curr.i;
					ny = curr.j;
				}
				if(dp[nx][ny][curr.k] > 1 + curr.w) {
					dp[nx][ny][curr.k] = 1 + curr.w;
					q.add(new Vertex(nx, ny, curr.k, dp[nx][ny][curr.k]));
				}
			}
			if(curr.k < ops.length()) {
				int nx = curr.i;
				int ny = curr.j;
				if(nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] != '#') {
					if(dp[nx][ny][curr.k+1] > 1 + curr.w) {
						dp[nx][ny][curr.k+1] = 1 + curr.w;
						q.add(new Vertex(nx, ny, curr.k+1, dp[nx][ny][curr.k+1]));
					}
				}
				if(ops.charAt(curr.k) == 'U') nx--;
				if(ops.charAt(curr.k) == 'D') nx++;
				if(ops.charAt(curr.k) == 'L') ny--;
				if(ops.charAt(curr.k) == 'R') ny++;
				if(nx < 0 || nx >= r || ny < 0 || ny >= c || grid[nx][ny] == '#') {
					nx = curr.i;
					ny = curr.j;
				}
				if(dp[nx][ny][curr.k+1] > curr.w) {
					dp[nx][ny][curr.k+1] = curr.w;
					q.add(new Vertex(nx, ny, curr.k+1, dp[nx][ny][curr.k+1]));
				}
			}
		}
		System.out.println(ret);
	}

	static class Vertex implements Comparable<Vertex> {
		public int i, j, k, w;
		public Vertex(int a, int b, int c, int d) {
			i=a;
			j=b;
			k=c;
			w=d;
		}
		public int compareTo(Vertex curr) {
			return w - curr.w;
		}
	}

}

