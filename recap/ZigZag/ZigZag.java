import java.util.*;
public class ZigZag {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] l = new int[n];
		int[][] dp = new int[n][2];
		int ret = 0;
		for(int i = 0; i < n; i++) {
			l[i] = scan.nextInt();
			Arrays.fill(dp[i], 1);
			for(int j = 0; j < i; j++) {
				if(l[i] > l[j]) {
					dp[i][1] = Math.max(dp[i][1], dp[j][0] + 1);
				}
				else if(l[i] < l[j]) {
					dp[i][0] = Math.max(dp[i][0], dp[j][1] + 1);
				}
			}
			ret = Math.max(ret, Math.max(dp[i][0], dp[i][1]));
		}
		System.out.println(ret);
	}	
}

