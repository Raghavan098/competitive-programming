import java.util.*;
public class Postman {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int k = scan.nextInt();
		long[] pos = new long[10000001];
		long[] neg = new long[10000001];
		for(int i = 0; i < n; i++) {
			int loc = scan.nextInt();
			int amt = scan.nextInt();
			(loc < 0 ? neg : pos)[Math.abs(loc)] += amt;
		}
		System.out.println(compute(pos, k) + compute(neg, k));
	}

	public static long compute(long[] locs, int k) {
		long ret = 0;
		long processed = 0;
		int last = 0;
		for(int i = locs.length-1; i >= 0; i--) {
			if(locs[i] == 0) continue;
			if(processed > 0) {
				long increase = Math.min(k - processed, locs[i]);
				processed += increase;
				locs[i] -= increase;
				if(processed == k) {
					ret += 2*last;
					processed = 0;
				}
			}
			if(locs[i] > 0) {
				long complete = locs[i] / k;
				locs[i] %= k;
				ret += 2 * complete * i;
			}
			if(processed == 0 && locs[i] > 0) {
				last = i;
				processed += locs[i];
				locs[i] = 0;
			}
		}
		if(processed > 0) {
			ret += 2 * last;
		}
		return ret;
	}

}
