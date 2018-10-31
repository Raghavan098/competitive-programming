import java.util.*;
public class MismatchedSocks {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		long sum = 0;
		long max = 0;
		while(n-- > 0) {
			int curr = scan.nextInt();
			sum += curr;
			max = Math.max(curr, max);
		}
		System.out.println(Math.min(sum / 2, sum - max));
	}	
}

