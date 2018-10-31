import java.util.*;
public class Alphabet {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int[] dp = new int[27];
	        String s = scan.nextLine() ;
		for (int j=0; j<s.length(); j++) {
			int currIndex = s.charAt(j) - 'a' + 1;
			int[] next = new int[27];
			for(int i = 0; i < dp.length; i++) {
				next[i] = dp[i];
			}
			for(int i = 0; i < currIndex; i++) {
				next[currIndex] = Math.max(next[currIndex], dp[i] + 1);
			}
			dp = next;
		}
		int ret = 0;
		for(int out: dp) {
			ret = Math.max(ret, out);
		}
		System.out.println(26 - ret);
	}
}

