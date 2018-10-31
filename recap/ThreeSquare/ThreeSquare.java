import java.util.*;
public class ThreeSquare {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int[][] grid = new int[3][2];
		int area = 0;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 2; j++) {
				grid[i][j] = scan.nextInt();
			}
			area += grid[i][0] * grid[i][1];
		}
		int side = (int)Math.sqrt(area);
		if(side * side != area) {
			System.out.println("NO");
		}
		else {
			System.out.println(can(new boolean[3], grid, side, side) ? "YES" : "NO");
		}
	}
	
	public static boolean can(boolean[] used, int[][] sides, int s1, int s2) {
		int amtAvail = 0;
		for(boolean out: used) {
			if(!out) {
				amtAvail++;
			}
		}
		if(amtAvail == 1) {
			for(int i = 0; i < sides.length; i++) {
				if(!used[i]) {
					return (sides[i][0] == s1 && sides[i][1] == s2) || (sides[i][0] == s2 && sides[i][1] == s1);
				}
			}
			throw new RuntimeException();
		}
		for(int i = 0; i < sides.length; i++) {
			if(!used[i]) {
				used[i] = true;
				if(sides[i][0] == s1 && sides[i][1] < s2 && can(used, sides, s1, s2 - sides[i][1])) {
					return true;
				}
				if(sides[i][0] == s2 && sides[i][1] < s1 && can(used, sides, s1 - sides[i][1], s2)) {
					return true;
				}
				if(sides[i][1] == s1 && sides[i][0] < s2 && can(used, sides, s1, s2 - sides[i][0])) {
					return true;
				}
				if(sides[i][1] == s2 && sides[i][0] < s1 && can(used, sides, s1 - sides[i][0], s2)) {
					return true;
				}
				used[i] = false;
			}
		}
		return false;
	}
	
}

