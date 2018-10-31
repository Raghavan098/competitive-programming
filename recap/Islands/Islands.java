import java.util.*;
public class Islands {
	static int[] dx = new int[]{-1,1,0,0};
	static int[] dy = new int[]{0,0,-1,1};
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
		int ret = 0;
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(grid[i][j] == 'L') {
					ret++;
					clear(grid, i, j);
				}
			}
		}
		System.out.println(ret);
	}
	
	public static void clear(char[][] grid, int x, int y) {
		if(x < 0 || x >= grid.length || y < 0 || y >= grid[x].length || grid[x][y] == 'W' || grid[x][y] == 'X') return;
		grid[x][y] = 'X';
		for(int k = 0; k < dx.length; k++) {
			clear(grid, x+dx[k], y+dy[k]);
		}
	}
	
}

