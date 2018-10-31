import java.util.*;
public class Barbells {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int k = scan.nextInt();
		int[] list = new int[n];
		for(int i = 0; i < n; i++) {
			list[i] = scan.nextInt();
		}
		int[] amt = new int[k];
		for(int i = 0; i < k; i++) {
			amt[i] = scan.nextInt();
		}
		TreeSet<Integer> ret = new TreeSet<Integer>();
		int maxMask = 1;
		for(int i = 0; i < k; i++) {
			maxMask *= 3;
		}
		for(int mask = 0; mask < maxMask; mask++) {
			int t = mask;
			int l = 0;
			int r = 0;
			for(int i = 0; i < k; i++) {
				if(t%3 == 1) {
					l += amt[i];
				}
				else if(t%3 == 2) {
					r += amt[i];
				}
				t /= 3;
			}
			if(l == r) {
				for(int out: list) {
					ret.add(out + l + r);
				}
			}
		}
		for(int out: ret) {
			System.out.println(out);
		}
	}
}

